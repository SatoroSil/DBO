using System;
using System.Text;
using System.Runtime.InteropServices;
using Microsoft.Win32;
using System.Windows.Forms;
using System.IO;


namespace Babidi
{
    /// <summary>
    /// WinAPI�� GetPrivateProfileString�� WritePrivateprofileString �Լ��� ����ϱ� ���� �Ŵ��� Ŭ����
    /// </summary>
    public class CIniManager
    {
        // ---- ini ���� �� �а� ���⸦ ���� API �Լ� ���� ----
        [DllImport("kernel32.dll")]
        private static extern int GetPrivateProfileString(    // ini Read �Լ�
                    String section,
                    String key,
                    String def,
                    StringBuilder retVal,
                    int size,
                    String filePath);

        [DllImport("kernel32.dll")]
        private static extern long WritePrivateProfileString(  // ini Write �Լ�
                    String section,
                    String key,
                    String val,
                    String filePath);

        /// <summary>
        /// INI ���Ͽ� ����
        /// </summary>
        /// <param name="Section">���̺�</param>
        /// <param name="Key">Ű��</param>
        /// <param name="Value">��</param>
        /// <param name="avsPath">INI ����</param>
        public static void G_IniWriteValue(String Section, String Key, String Value, string avsPath)
        {
            try
            {
                String strPath = Application.StartupPath + "\\" + avsPath;

                WritePrivateProfileString(Section, Key, Value, strPath);
            }
            catch (System.Exception e)
            {
                // TODO : LogMessage
                MessageBox.Show(e.Message);
                return;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Section"></param>
        /// <param name="Key"></param>
        /// <param name="avsPath"></param>
        /// <returns></returns>
        public static String G_IniReadValue(String Section, String Key, string avsPath)
        {
            try
            {
                String strPath = Application.StartupPath + "\\" + avsPath;

                StringBuilder temp = new StringBuilder(2000);
                int i = GetPrivateProfileString(Section, Key, "", temp, 2000, strPath);

                return temp.ToString();
            }
            catch (System.Exception e)
            {
                MessageBox.Show(e.Message);
                // Todo : LogMeessage
                return null;
            }
        }
    }
}