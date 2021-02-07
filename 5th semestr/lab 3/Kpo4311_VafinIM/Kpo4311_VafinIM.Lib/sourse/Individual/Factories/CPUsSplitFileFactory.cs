using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kpo4311.VafinIM.Lib
{
    public class CPUsSplitFileFactory : ICPUsFactory
    {
        public ICPUsListSaver CreateCPUsListSaver()
        {
            return new CPUsListSplitFileSaver(AppGlobalSettings.dataFileName);

        }
        public ICPUsListLoader CreateCPUsListLoader()
        {
            return new CPUsListSplitFileLoader(AppGlobalSettings.dataFileName);
        }
    }
}
