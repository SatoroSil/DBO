using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Xml;

using ICSharpCode.SharpZipLib.Zip;
using ICSharpCode.SharpZipLib.Zip.Compression.Streams;

namespace ERSMService.Main
{
    class ERSMWorker
    {
        private List<ErrorReportFile> listErrorReport;

        public void StartWork()
        {
            listErrorReport = new List<ErrorReportFile>();

            Console.WriteLine(DateTime.Now.ToShortTimeString() + " #Work Thread is Start...");

            // 1. ������ �������� �����´�.
            if (GetListZipFiles(ERSMConfig.ERSFolder))
            {
                Console.WriteLine(DateTime.Now.ToShortTimeString() + "Get Error Report List(Zip Files) Successs...");
            }
            else
            {
                Console.WriteLine(DateTime.Now.ToShortTimeString() + "Get Error Report List(Zip FIles) Fail!!");
                return;
            }

            // 2. ���� �̸��� �����Ͽ� ���� ������ �����Ѵ�.
            if (RenameZipFiles())
            {
                Console.WriteLine(DateTime.Now.ToShortTimeString() + "Error Report File Process Success..");
            }
            else
            {
                Console.WriteLine(DateTime.Now.ToShortTimeString() + "Error Report File Process Fail!");
                return;
            }
        }

        private bool GetListZipFiles(string folderName)
        {
            // 1. ���� ������ �˻��Ѵ�. (���� ����Ʈ ������ ��Ʈ �������� 1�ܰ� ���� ������ �����Ѵ�)
            string[] subDirList =  Directory.GetDirectories(folderName);            
            
            // 2. ���� �������� ZipFile���� �˻��Ѵ�.
            foreach (string subDir in subDirList)
            {
                string[] zipFiles = Directory.GetFiles(subDir, "*.zip", SearchOption.TopDirectoryOnly);
                foreach (string zipFile in zipFiles)
                {
                    // ���� ������ ����Ʈ�� ��´�.                    
                    DateTime dtCreate = File.GetCreationTime(zipFile);
                    ErrorReportFile reportFile = new ErrorReportFile();
                    reportFile.folderName = subDir;             // ���� �̸�
                    reportFile.fileName = Path.GetFileName(zipFile);              // ���� �̸�
                    reportFile.fileDate = string.Format("{0:D}{1:00}{2:00}", dtCreate.Year, dtCreate.Month, dtCreate.Day); // ���� ���� ��¥
                    reportFile.userID = GetUserIDFromZipFile(zipFile);
                    listErrorReport.Add(reportFile);
                }
            }

            return true;
        }

        /// <summary>
        /// zip ���ϳ����� ���� ID�� �����´�.
        /// </summary>
        /// <param name="zipFileName"></param>
        /// <returns></returns>
        private string GetUserIDFromZipFile(string zipFileName)
        {
            ZipInputStream zis = new ZipInputStream(File.OpenRead(zipFileName));
            if (zis == null)
            {
                Console.WriteLine("UnZip is Fail!! " + zipFileName);
                return null;
            }

            ZipEntry theEntry;
            while((theEntry = zis.GetNextEntry()) != null)
            {
                string fileName = Path.GetFileName(theEntry.Name);
                if(fileName == ERSMConfig.idFileName) 
                {
                    XmlTextReader reader = new XmlTextReader(zis);
                    reader.WhitespaceHandling = WhitespaceHandling.None;   
                    while(reader.Read())
                    {
                        reader.MoveToContent();
                        
                        // ���� ID�� ����ִ� ��带 ã���Ŀ� �� ���� ��ȯ�Ѵ�.
                        if(reader.NodeType == XmlNodeType.Element && reader.Name == ERSMConfig.nodeUserIDElement)
                        {
                            reader.Read();
                            zis.Close();
                            return reader.Value;
                        }
                    }
                }
            }

            zis.Close();
            return null;
        }

        private bool RenameZipFiles()
        {
            foreach(ErrorReportFile report in listErrorReport)
            {
                // ��¥�� ������ �����Ѵ�.
                string newFolderName = report.folderName + @"\" + report.fileDate;
                Directory.CreateDirectory(newFolderName);

                // ������ ������ ���� �̸��� �����Ͽ� �ִ´�.
                string oldFileName = report.folderName + @"\" + report.fileName;
                string newFileName = newFolderName + @"\" + report.userID + "_" + report.fileName;
                try
                {
                    File.Move(oldFileName, newFileName);
                }
                catch(Exception ex)
                {
                    continue;
                }

                Console.WriteLine("Rename File : " + oldFileName + " -> " + newFileName);
            }
            return true;
        }
    }    
}
