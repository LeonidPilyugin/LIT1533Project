using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sputnik
{
    public class ResetInformationItem : StaticObject
    {
        public ResetInformationItem() : base() { }
        public ResetInformationItem(double latitudes, double longitudes) : base(latitudes, longitudes) { }
    }
}
