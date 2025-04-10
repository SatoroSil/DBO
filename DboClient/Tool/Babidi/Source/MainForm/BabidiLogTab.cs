using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Drawing;
using System.Text;
using System.IO;

namespace Babidi
{
    public partial class MainForm : Form
    {
        /// <summary>
        /// Babidi.eLogType �� ����ϴ� ���ڿ�
        /// </summary>
        String[] m_strType;

        /// <summary>
        /// Babidi Log�� �ʱ�ȭ�ϰ� ���õ� ����� �ڿ��� �ʱ�ȭ�Ѵ�.
        /// </summary>
        protected void InitBabidiLog()
        {
            // TYPE�� String���� ����
            m_strType = new String[(int)eLogType.eLOGTYPE_NUMS];

            m_strType[(int)eLogType.eLOGTYPE_FILE]  = "FILE ERROR";
            m_strType[(int)eLogType.eLOGTYPE_ID]    = "ID MISS";
            m_strType[(int)eLogType.eLOGTYPE_LINE_OVER] = "LINE OVER";
            m_strType[(int)eLogType.eLOGTYPE_LENGTH_OVER] = "LENGTH OVER";
            m_strType[(int)eLogType.eLOGTYPE_CONFIG] = "CONFIG";
            
            // �ٺ�� �α��� ����Ʈ ���� ��Ÿ���� �����Ѵ�.
            listLog.View = View.Details;
            listLog.Dock = DockStyle.Fill;
            listLog.LabelEdit = false;
            listLog.GridLines = true;
            
            int nWidth = tabLocalize.Width;

            listLog.Columns.Add("ID", (int)((float)nWidth * 0.03f), HorizontalAlignment.Center);
            listLog.Columns.Add("TIME", (int)((float)nWidth * 0.15f), HorizontalAlignment.Center);
            listLog.Columns.Add("TYPE", (int)((float)nWidth * 0.07f), HorizontalAlignment.Center);
            listLog.Columns.Add("PLACE", (int)((float)nWidth * 0.15f), HorizontalAlignment.Center);
            listLog.Columns.Add("LOG", (int)((float)nWidth * 0.58f), HorizontalAlignment.Center);

            listLog.Resize += new EventHandler(OnResizeListLog);
        }

        /// <summary>
        /// ����Ʈ���� ��Ʈ���� �������� �� �� �߻��ϴ� �̺�Ʈ �Լ�
        /// </summary>
        /// <param name="sender">�̺�Ʈ�� ������ ��ü</param>
        /// <param name="e">�̺�Ʈ�� ����ü</param>
        void OnResizeListLog(object sender, EventArgs e)
        {
            //int nWidth = tabLocalize.Width;

            //listLog.Columns[0].Width = (int)((float)nWidth * 0.03f);
            //listLog.Columns[1].Width = (int)((float)nWidth * 0.15f);
            //listLog.Columns[2].Width = (int)((float)nWidth * 0.07f);
            //listLog.Columns[3].Width = (int)((float)nWidth * 0.15f);
            //listLog.Columns[4].Width = (int)((float)nWidth * 0.58f);
        }

        /// <summary>
        /// Log�� ���� Index
        /// </summary>
        protected int m_nLogIndex = 0;

        /// <summary>
        /// Babidi_Log�� Log�� ����Ѵ�.
        /// </summary>
        /// <param name="nType">Ÿ���� ���ڿ�</param>
        /// <param name="strPlace">����� ���ڿ�</param>
        /// <param name="strLog">�α��� ���ڿ�</param>
        public void AddLog(int nType, string strPlace, string strLog)
        {
            // ID �� ����Ʈ ������ ����
            String strID = String.Format("{0}", m_nLogIndex);
            ListViewItem lvi_log = new ListViewItem(strID);

            // ����ð�
            DateTime nowTime = DateTime.Now;
            lvi_log.SubItems.Add(nowTime.ToString());

            // TYPE
            string strFileLog = String.Format("{0,3} - {1} : ", m_nLogIndex, DateTime.Now.ToShortTimeString() );
            if (nType > m_strType.Length - 1)
            {
                lvi_log.SubItems.Add("UNKNOWN");
                strFileLog += "UNKNOWN : ";
            }
            else
            {
                lvi_log.SubItems.Add(m_strType[nType]);
                strFileLog += m_strType[nType] + " : ";
            }

            // PLACE
            lvi_log.SubItems.Add(strPlace);
            strFileLog += "[" + strPlace + "] ";

            // Log
            lvi_log.SubItems.Add(strLog);
            strFileLog += strLog;

            // ����Ʈ�信 ������ �߰�
            listLog.Items.Add(lvi_log);

            // File�� ����.
            string strFileName =  String.Format("BabidiLog{0}.txt", DateTime.Today.ToShortDateString() );
            AddFileLog(strFileName, strFileLog);

            if (nType.CompareTo((int)eLogType.eLOGTYPE_FILE) == 0)
                MessageBox.Show(strPlace + strLog, m_strType[nType].ToString());

            m_nLogIndex++;

            FocusTab();
        }

        public void AddFileLog(string strFile, string strLog)
        {
            try
            {
                using (FileStream fs = new FileStream(strFile, FileMode.Append, FileAccess.Write))
                {
                    using (StreamWriter sw = new StreamWriter(fs, Encoding.Unicode))
                    {
                        sw.WriteLine("{0}", strLog);
                        sw.Close();
                    }
                }
            }
            catch(Exception e)
            {
                MessageBox.Show(e.Message);
            }
        }

        /// <summary>
        /// Baibidi_Log Tab�� ��Ȱ��ȭ �Ǿ� �ִٸ� Ȱ��ȭ �����ش�.
        /// </summary>
        public void FocusTab()
        {
            //tabLocalize.TabPages["tabLog"].BackColor = Color.Red;
            tabLocalize.SelectTab("tabLog");
        }
    }
}
