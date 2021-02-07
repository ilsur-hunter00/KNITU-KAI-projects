using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kpo4311.VafinIM.Lib
{
    public interface ICPUsFactory
    {
        ICPUsListSaver CreateCPUsListSaver();
        ICPUsListLoader CreateCPUsListLoader();
    }
}
