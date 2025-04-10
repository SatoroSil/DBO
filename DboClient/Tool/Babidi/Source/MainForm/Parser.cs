using System;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.Windows.Forms;
using System.IO;
using System.Drawing;

namespace Babidi
{
    public partial class MainForm : Form
    {
        
        public Boolean LoadData(DATA_SYNC eSync, DATA_TYPE eType, String filename)
        {
            // StreamReader�� ������ �ε��ϴ� �κ��� ���ܸ� ó���ϵ��� �Ѵ�.
            try
            {
                if (eSync == DATA_SYNC.DATA_CLIENT)
                {
                    // �ؽ�Ʈ ������ Default Encoding(ANSI)�� StreamReader�� �ҷ����δ�.
                    using (StreamReader sr = new StreamReader(filename, Encoding.Unicode))
                    {
                        String line;

                        while ((line = sr.ReadLine()) != null)
                        {
                            switch (eType)
                            {
                                case DATA_TYPE.DATA_TYPE_DEF:
                                    ParseDef(ref m_tblClient, line);
                                    break;
                                case DATA_TYPE.DATA_TYPE_ALARM:
                                    ParseAlarmType(ref m_tblClient, line);
                                    break;
                                case DATA_TYPE.DATA_TYPE_KOR:
                                    ParseKorData(ref m_tblClient, line);
                                    break;
                                case DATA_TYPE.DATA_TYPE_JPN:
                                    ParseJpnData(ref m_tblClient, line);
                                    break;
                                case DATA_TYPE.DATA_TYPE_USER:
                                    {
                                        String strNote = sr.ReadLine();
                                        ParseUserData(ref m_tblClient, line, strNote);
                                        break;
                                    }
                            }
                        }

                        sr.Close();
                    }
                }
                else if (eSync == DATA_SYNC.DATA_SERVER)
                {
                    // �ؽ�Ʈ ������ Default Encoding(ANSI)�� StreamReader�� �ҷ����δ�.
                    using (StreamReader sr = new StreamReader(filename, Encoding.Unicode))
                    {
                        String line;

                        while ((line = sr.ReadLine()) != null)
                        {
                            switch (eType)
                            {
                                case DATA_TYPE.DATA_TYPE_DEF:
                                    ParseDef(ref m_tblServer, line);
                                    break;
                                case DATA_TYPE.DATA_TYPE_ALARM:
                                    ParseAlarmType(ref m_tblServer, line);
                                    break;
                                case DATA_TYPE.DATA_TYPE_KOR:
                                    ParseKorData(ref m_tblServer, line);
                                    break;
                                case DATA_TYPE.DATA_TYPE_JPN:
                                    ParseJpnData(ref m_tblServer, line);
                                    break;
                                case DATA_TYPE.DATA_TYPE_USER:
                                    {
                                        String strNote = sr.ReadLine();
                                        ParseUserData(ref m_tblServer, line, strNote);
                                        break;
                                    }
                            }
                        }

                        sr.Close();
                    }
                }
                else
                {
                }
            }
            catch (System.Exception e)
            {
                AddLog((int)Babidi.eLogType.eLOGTYPE_FILE, e.Source, e.Message);

                return false;
            }

            return true;
        }

       

        protected Boolean ParseDef(ref DataTable table, String strDef)
        {
            // ���ڿ��� �հ� �ڿ� ���� ����
            strDef = strDef.Trim();

            // ���ڿ��� ���̰� 2���ڰ� �ȵǸ� ����
            if (strDef.Length < 2)
                return false;

            // ���� ���� ��ū�� ����
            if (strDef[0] == '/' && strDef[1] == '/')
                return false;

            if (strDef[0] == '{' || strDef[0] == '}')
                return false;

            if (strDef[0] == ';' || strDef[0] == '#' )
                return false;

            if (strDef.Length > 4)
            {
                if (strDef[0] == 'e' &&
                    strDef[1] == 'n' &&
                    strDef[2] == 'u' &&
                    strDef[3] == 'm')
                    return false;
            }

            // ù ���ں��� �ּ��� �ƴ϶�� �ּ��� �ִ� ���� ã�Ƽ� ����Ѵ�.
            System.Int32 nCommentPos = strDef.IndexOf("//");

            // , �� ��ã�Ҵٸ� ���ǰ� �ƴϴ�.
            System.Int32 nDefinePos = strDef.IndexOf(',');
            //if (nDefinePos < 0)
            //    return false;

            // Equal�� �����ϴ� ��쵵 �ִ�. ( �ּ� �ڿ� ���� �ʴ´ٸ� )
            System.Int32 nDefinePosEqual = strDef.IndexOf('=');
            if (nDefinePosEqual >= 0 && nCommentPos > nDefinePosEqual )
            {
                nDefinePos = nDefinePosEqual;
            }

            if (nDefinePos < 0)
            {
                // �ּ��� �ִ�.
                if (nCommentPos >= 0)
                    nDefinePos = nCommentPos;
                else
                    nDefinePos = strDef.Length;
            }
            
            String strRealDef = strDef.Substring(0, nDefinePos);
            strRealDef = strRealDef.Trim();

            strRealDef = strRealDef.Trim();

            while (strRealDef.Contains("\t"))
            {
                System.Int32 nTabPos = strRealDef.IndexOf('\t');
                strRealDef = strRealDef.Remove(nTabPos, 1);
            }

            // Row �߰�
            DataRow row = table.NewRow();
            row[COL_DEFINE] = strRealDef;

            // Comment �� ������ Comment�� �߰�
            if (nCommentPos > -1)
            {
                String strComment = strDef.Substring(nCommentPos, strDef.Length - nCommentPos);
                row[COL_COMMENT] = strComment;
            }

            table.Rows.Add(row);

            return true;
        }

        

        protected Boolean ParseAlarmType(ref DataTable table, String strAlarm)
        {
            // ���ڿ��� �� �� ���� ����
            strAlarm = strAlarm.Trim();

            // ���ڿ��� ���̰� 2���ڰ� �ȵǸ� ����
            if (strAlarm.Length < 2)
                return false;

            // ù ���ں��� �ּ��̶�� ����
            if (strAlarm[0] == '/' && strAlarm[1] == '/')
                return false;

            // ù ���ں��� �ּ��� �ƴ϶�� �ּ��� �ִ� ���� ã�Ƽ� ����Ѵ�.
            System.Int32 nCommentPos = strAlarm.IndexOf("//");

            // = �� ��ã�Ҵٸ� ���ǰ� �ƴϴ�.
            System.Int32 nDefinePos = strAlarm.IndexOf('=');
            if (nDefinePos < 0)
                return false;

            // ���Ǹ� ���
            String strDef = strAlarm.Substring(0, nDefinePos);

            // ; �� ������ ������ ���� �ƴϴ�. �̰��� ����!
            System.Int32 nEndPos = strAlarm.IndexOf(';');
            if (nEndPos <= 0)
                return false;

            // Ÿ���� ���
            String strType = strAlarm.Substring(nDefinePos + 1, strAlarm.Length - nDefinePos - 2);

            // ���ǿ� Ÿ�� �� ���� �� �� ������ �������ش�.
            strDef = strDef.Trim();
            strType = strType.Trim();

            // 1. DEFINE�� �ش��ϴ� ROW�� ã�´�.
            DataRow row = table.Rows.Find(strDef);
            if (row == null)
            {
                AddLog((int)Babidi.eLogType.eLOGTYPE_ID, table.ToString(), strAlarm);
                return false;
            }

            row[COL_ALARMTYPE] = strType;

            return true;
        }

       
        protected Boolean ParseKorData(ref DataTable table, String strKor)
        {
            // ���ڿ��� �� �� ���� ����
            strKor = strKor.Trim();

            // ���ڿ��� ���̰� 2���ڰ� �ȵǸ� ����
            if (strKor.Length < 2)
                return false;

            // ù ���ں��� �ּ��̶�� ����
            if (strKor[0] == '/' && strKor[1] == '/')
                return false;

            // ù ���ں��� �ּ��� �ƴ϶�� �ּ��� �ִ� ���� ã�Ƽ� ����Ѵ�.
            System.Int32 nCommentPos = strKor.IndexOf("//");

            // = �� ��ã�Ҵٸ� ���ǰ� �ƴϴ�.
            System.Int32 nDefinePos = strKor.IndexOf('=');
            if (nDefinePos < 0)
                return false;

            // ���Ǹ� ���
            String strDef = strKor.Substring(0, nDefinePos);
        
            // Ÿ���� ���
            String strData = strKor.Substring(nDefinePos + 1, strKor.Length - nDefinePos - 1);

            // ���ǿ� Ÿ�� �� ���� �� �� ������ �������ش�.
            strDef = strDef.Trim();
            strData = strData.Trim();

            // Data�� �� �� ����ǥ�� �������ش�. ( �յ� ���ڿ� �ϳ��� �߶��ش�. )
            strData = strData.Substring(1, strData.Length - 2);

            DataRow row = table.Rows.Find(strDef);
            if (row == null)
            {
                AddLog((int)Babidi.eLogType.eLOGTYPE_ID, table.ToString(), strKor);
                return false;
            }

            row[COL_KOR] = strData;

            return true;
        }

      

        protected Boolean ParseJpnData(ref DataTable table, String strJpn)
        {
            // ���ڿ��� �� �� ���� ����
            strJpn = strJpn.Trim();

            // ���ڿ��� ���̰� 2���ڰ� �ȵǸ� ����
            if (strJpn.Length < 2)
                return false;

            // ù ���ں��� �ּ��̶�� ����
            if (strJpn[0] == '/' && strJpn[1] == '/')
                return false;

            // ù ���ں��� �ּ��� �ƴ϶�� �ּ��� �ִ� ���� ã�Ƽ� ����Ѵ�.
            System.Int32 nCommentPos = strJpn.IndexOf("//");

            // = �� ��ã�Ҵٸ� ���ǰ� �ƴϴ�.
            System.Int32 nDefinePos = strJpn.IndexOf('=');
            if (nDefinePos < 0)
                return false;

            // ���Ǹ� ���
            String strDef = strJpn.Substring(0, nDefinePos);

            // Ÿ���� ���
            String strData = strJpn.Substring(nDefinePos + 1, strJpn.Length - nDefinePos - 1);

            // ���ǿ� Ÿ�� �� ���� �� �� ������ �������ش�.
            strDef = strDef.Trim();
            strData = strData.Trim();

            // Data�� �� �� ����ǥ�� �������ش�. ( �յ� ���ڿ� �ϳ��� �߶��ش�. )
            strData = strData.Substring(1, strData.Length - 2);

            DataRow row = table.Rows.Find(strDef);
            if (row == null)
            {
                AddLog((int)Babidi.eLogType.eLOGTYPE_ID, table.ToString(), strJpn);
                return false;
            }

            row[COL_JPN] = strData;

            return true;
        }

      

        protected Boolean ParseUserData(ref DataTable table, String strDefRule, String strNote)
        {
            // ���ڿ��� �� �� ���� ����
            strDefRule = strDefRule.Trim();

            // ���ڿ��� ���̰� �ƹ��͵� ������ ����
            if (strDefRule.Length <= 0)
                return false;

            // = �� ��ã�Ҵٸ� ���ǰ� �ƴϴ�.
            System.Int32 nDefinePos = strDefRule.IndexOf('=');
            if (nDefinePos < 0)
                return false;

            // ���Ǹ� ���
            String strDef = strDefRule.Substring(0, nDefinePos);

            // Ÿ���� ���
            String strType = strDefRule.Substring(nDefinePos + 1, strDefRule.Length - nDefinePos - 1);

            // ���ǿ� Ÿ�� �� ���� �� �� ������ �������ش�.
            strDef = strDef.Trim();
            strType = strType.Trim();

            String[] aStrType = strType.Split(',');

            // 3���� ������ HTML, LENG�� Error
            if (aStrType.Length < 3)
            {
                // Log
                return false;
            }

            DataRow row = table.Rows.Find(strDef);
            if (row == null)
            {
                AddLog((int)Babidi.eLogType.eLOGTYPE_ID, table.ToString(), strDef);
                return false;
            }

            row[COL_HTML] = aStrType[0];
            row[COL_LINELENGTH] = String.Format("{0},{1}", aStrType[1], aStrType[2]);
            row[COL_NOTE] = strNote;

            return true;
        }
    }
}