using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.IO;
using System.Reflection;
using System.Threading;

namespace ERSMService.Main
{
    /**
     * \ingroup ERSMService
     * \brief �⺻ ���ǿ� Config ������ Load�Ͽ� �����ϴ� Ŭ����
     *
     * \date 2009-07-10
     * \author agebreak
     */ 
    class ERSMConfig
    {
        public static string configFileName = "ERSMConfig.xml";
        public static string idFileName = "DboErrorInfo.xml";          // DBO�� ���� ID ������ ������ �ִ� �α� ���� �̸�
        public static string nodeUserIDElement = "USER_ID";            // ���� ID�� ��� �ִ� ���
        public static string ERSFolder;
        public static int ERSMRunTime;

        public bool LoadConfig(string configFile)
        {
            try
            {
                string currentFolder = Path.GetDirectoryName(Assembly.GetAssembly(typeof(ERSMConfig)).CodeBase);
                currentFolder = currentFolder.Replace("file:\\", "");
                XmlTextReader reader = new XmlTextReader(currentFolder + @"\" + ERSMConfig.configFileName);
                reader.WhitespaceHandling = WhitespaceHandling.None;                
                while (reader.Read())
                {
                    reader.MoveToContent();
                    switch (reader.NodeType)
                    {
                        case XmlNodeType.Element:
                            if (reader.Name == "ERS_FOLDER")
                            {
                                reader.Read();
                                ERSMConfig.ERSFolder = reader.Value;                                
                            }
                            else if (reader.Name == "ERSM_RUNTIME")
                            {
                                reader.Read();
                                ERSMConfig.ERSMRunTime = Convert.ToInt32(reader.Value);
                            }                            
                            break;
                    }                    
                }
            }
            catch
            {
                Console.WriteLine("[Error] Config File Load Fail. - " + configFile);

                return false;
            }

            Console.WriteLine("Config File Read Success...");

            return true;
        }
    }
}
