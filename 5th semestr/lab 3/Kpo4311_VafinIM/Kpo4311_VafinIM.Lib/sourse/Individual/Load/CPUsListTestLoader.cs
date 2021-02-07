using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kpo4311.VafinIM.Lib
{
    public class CPUsListTestLoader : ICPUsListLoader
    {
        public CPUsListTestLoader()
        {
            this._CPUsList = new List<CPUs>();
        }

        private List<CPUs> _CPUsList;

        public List<CPUs> CPUsList
        {
            get { return _CPUsList; }
        }

        private ICPUsListLoader.LoadStatus _status = ICPUsListLoader.LoadStatus.None;

        public ICPUsListLoader.LoadStatus status
        {
            get => _status;
        }

        public void Execute()
        {
            try
            {
                {
                    CPUs cpus = new CPUs()
                    {
                        CPU = "Pentium-3",
                        frequency = 233,
                        RAM = 4000,
                        Type = "C",
                    };
                    _CPUsList.Add(cpus);
                }
                {
                    CPUs cpus = new CPUs()
                    {
                        CPU = "AMD-K6",
                        frequency = 166,
                        RAM = 6000,
                        Type = "C",
                    };
                    _CPUsList.Add(cpus);
                }
                {
                    CPUs cpus = new CPUs()
                    {
                        CPU = "PowerPC-620",
                        frequency = 2000,
                        RAM = 8000,
                        Type = "R",
                    };
                    _CPUsList.Add(cpus);
                    _status = ICPUsListLoader.LoadStatus.Success;
                }
            }
            catch (Exception ex)
            {
                LogUtility.ErrorLog(ex);
                _status = ICPUsListLoader.LoadStatus.GeneralError;
            }
        }
    }
    /*catch (Exception ex) {
        LogUtility.ErrorLog(ex);
        _status = ICPUsListLoader.LoadStatus.GeneralError;
    }*/
}
