using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace ERSMService.Main
{
    class ERSMMain
    {
        ERSMConfig ersmConfig = new ERSMConfig();
        DateTime dtPrevRun;

        public void Start()
        {            
            Console.WriteLine("--- ERSM Service Start ----");

            // Config ������ Load �Ѵ�.
            if(ersmConfig.LoadConfig(ERSMConfig.configFileName))
            {
                Console.WriteLine("ERSM Config File Read Success...");
            }
            else
            {
                Console.WriteLine("ERSM Config File Read Fail!!");
                return;
            }

            Thread mainThread = new Thread(this.MainLoop);
            mainThread.IsBackground = true;
            mainThread.Start();            
        }
        
        /// <summary>
        /// ���� ������ ���鼭 �ð��� �Ǹ� �����带 �۵���Ų��.
        /// </summary>
        private void MainLoop()
        {
            // ó�� �����Ҷ� �ѹ��� ������ ������.            
            dtPrevRun = DateTime.Now;

            DateTime dtCurrent = DateTime.Now;
            ERSMWorker ersmWorker = new ERSMWorker();
            ersmWorker.StartWork();

            while(true)
            {
                dtCurrent = DateTime.Now;
                TimeSpan tsGap = dtCurrent - dtPrevRun;
                if(tsGap.Minutes >= ERSMConfig.ERSMRunTime)
                {
                    Thread ersmWorkerThread = new Thread(ersmWorker.StartWork);
                    ersmWorkerThread.IsBackground = true;
                    ersmWorkerThread.Start();
                }

                // 1�� ������ ����
                Thread.Sleep(1000 * 60);
            }
        }
    }
}
