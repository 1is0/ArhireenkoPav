using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;

namespace LR7
{
    public class RatNum : IComparable<RatNum>, IEquatable<RatNum>
    {
        //       whole/natural        //
        private readonly int whole;
        private readonly int natural;

        public RatNum(int new_whole, int new_natural)
        {
            whole = new_whole;
            natural = new_natural;
        }

        ~RatNum() { }

        public static RatNum operator +(RatNum n1, RatNum n2)
        {
            RatNum result;
            if (n1.natural == n2.natural)
                result = new RatNum(n1.whole + n2.whole, n1.natural);
            else
                result = new RatNum((n1.whole * n2.natural) + (n2.whole * n1.natural), n1.natural * n2.natural);

            return result;
        }

        public static RatNum operator -(RatNum n1, RatNum n2)
        {
            RatNum result;
            if (n1.natural == n2.natural)
                result = new RatNum(n1.whole - n2.whole, n1.natural);
            else
                result = new RatNum((n1.whole * n2.natural) - (n1.natural * n2.whole), n1.natural * n2.natural);
            return result;
        }

        public static RatNum operator *(RatNum n1, RatNum n2)
        {
            RatNum result = new RatNum(n1.whole * n2.whole, n1.natural * n2.natural);
            return result;
        }

        public static RatNum operator /(RatNum n1, RatNum n2)
        {
            RatNum result = new RatNum(n1.whole * n2.natural, n1.natural * n2.whole);
            return result;
        }


        public static bool operator >(RatNum n1, RatNum n2)
        {
                RatNum res1 = new RatNum(n1.whole * n2.natural, n1.natural * n2.natural);
                RatNum res2 = new RatNum(n2.whole * n1.natural, n1.natural * n2.natural);
                if (res1.whole > res2.whole) return true;
                else return false;
            
        }

        public static bool operator <(RatNum n1, RatNum n2)
        {
                RatNum res1 = new RatNum(n1.whole * n2.natural, n1.natural * n2.natural);
                RatNum res2 = new RatNum(n2.whole * n1.natural, n1.natural * n2.natural);
                if (res1.whole < res2.whole) return true;
                else return false;
        }

        public static bool operator >=(RatNum n1, RatNum n2)
        {
                RatNum res1 = new RatNum(n1.whole * n2.natural, n1.natural * n2.natural);
                RatNum res2 = new RatNum(n2.whole * n1.natural, n1.natural * n2.natural);
                if (res1.whole >= res2.whole) return true;
                else return false;

        }

        public static bool operator <=(RatNum n1, RatNum n2)
        {
                RatNum res1 = new RatNum(n1.whole * n2.natural, n1.natural * n2.natural);
                RatNum res2 = new RatNum(n2.whole * n1.natural, n1.natural * n2.natural);
                if (res1.whole <= res2.whole) return true;
                else return false;
        }




        //Convertion
        public override string ToString()
        {
            return $"{whole}/{natural}";
        }

        //Eq check
        public bool Equals(RatNum nZ)
        {
            if (ReferenceEquals(null, nZ)) return false;
            if (ReferenceEquals(this, nZ)) return true;
            return whole == nZ.whole && natural == nZ.natural;
        }

        public int CompareTo(RatNum nZ)
        {
            if (this.whole * nZ.natural < nZ.whole * this.natural)
            {
                return 1;
            }
            else if (this.whole * nZ.natural > nZ.whole * this.natural)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }

        public static implicit operator int(RatNum nZ)
        {
            return (nZ.whole / nZ.natural);
        }

        public static implicit operator double(RatNum nZ)
        {
            return (double)nZ.whole / nZ.natural;
        }
    }
}
