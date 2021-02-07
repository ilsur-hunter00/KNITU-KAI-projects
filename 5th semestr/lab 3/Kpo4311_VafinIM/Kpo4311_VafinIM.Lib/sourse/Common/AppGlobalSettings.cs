using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Kpo4311.Utility;

namespace Kpo4311.VafinIM.Lib
{
    public static class AppGlobalSettings
    {
        private static string _logPath;
        public static string logPath
        {
            get => _logPath;
        }

        private static string _dataFileName;
        public static string dataFileName
        {
            get => _dataFileName;
        }

        private static ICPUsFactory _CPUsFactory;
        public static ICPUsFactory CPUsFactory
        {
            get => _CPUsFactory;
        }
        public static void Initialize()
        {
            AppConfigUtility acu = new AppConfigUtility();
            _logPath = acu.AppSettings("logPath");
            _dataFileName = acu.AppSettings("dataFileName");
            if (acu.AppSettings("CPUsFactory") == "SplitFile")
                _CPUsFactory = new CPUsSplitFileFactory();
            else
                _CPUsFactory = new CPUsTestFactory();
        }
    }
}
