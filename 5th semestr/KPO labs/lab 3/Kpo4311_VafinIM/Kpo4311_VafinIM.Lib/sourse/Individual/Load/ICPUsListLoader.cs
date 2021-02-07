using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
// загрузчик списка

namespace Kpo4311.VafinIM.Lib
{
    public interface ICPUsListLoader
    {
        List<CPUs> CPUsList { get; }
        public LoadStatus status { get; }
        void Execute();
        public enum LoadStatus
        {
            None = 0,
            Success = 1,
            FileNameIsEmpty = -1,
            FileNotExists = -2,
            GeneralError = -100
        }
    }
}
