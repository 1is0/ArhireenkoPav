using System;
using System.Text;
using System.Globalization;

namespace Example
{
    class Program
    {

        static void Main()
        {
            int k=0, l=0, i, m=0, start=0, j;
            StringBuilder text = new StringBuilder(" И поэтому все так произошло"); //пробел перед первым символом строки обязателен
            for (i = 0; i< text.Length; i++)        
            {
                if (text[i].Equals(' ')) k++;
            }
            StringBuilder words1 = new StringBuilder("                             "); //кол-во пробелов = кол-ву символов в изначальной строке, можно больше
            for (i = text.Length - 1; i >=0 ; i--)
            {
                if (i == text.Length-1 || text[i + 1].Equals(' ')) start = i;
                if (text[i].Equals(' ')||i==0)
                {
                    for (j = i; j < start+1; j++)
                    {
                        words1[l] = text[j];
                        l++;
                    }
                    
                }
            }
            Console.WriteLine(words1); 
        }
    }
}
