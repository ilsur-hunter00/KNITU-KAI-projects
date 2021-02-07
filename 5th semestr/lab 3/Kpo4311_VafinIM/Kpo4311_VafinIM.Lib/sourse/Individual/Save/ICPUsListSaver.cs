using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kpo4311.VafinIM.Lib
{
    public interface ICPUsListSaver
    {
        List<CPUs> CPUsList { set; }
        public LoadStatus status { get; }
        void Execute();
        public enum LoadStatus
        {
            None = 0,
            Success = 1,
            FileNameIsEmpty = -1,
            FileNotExists = -2,
            NoData = -3,
            GeneralError = -100
        }
    }
}
