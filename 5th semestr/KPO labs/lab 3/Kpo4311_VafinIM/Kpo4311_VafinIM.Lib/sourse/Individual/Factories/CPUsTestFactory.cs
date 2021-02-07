using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kpo4311.VafinIM.Lib
{
    public class CPUsTestFactory : ICPUsFactory
    {
        public ICPUsListSaver CreateCPUsListSaver()
        {
            return new CPUsListTestSaver();
        }

        public ICPUsListLoader CreateCPUsListLoader()
        {
            return new CPUsListTestLoader();
        }
    }
}
