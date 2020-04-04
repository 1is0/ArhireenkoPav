using System;
using System.Text;
using System.Globalization;

namespace Example
{
    class Lab2_2
    {

        static void Main()
        {
            int k=1, l=0, i, start=0, j;
            StringBuilder text = new StringBuilder("И поэтому все так произошло");
            for (i = 0; i< text.Length; i++)        
            {
                if (text[i].Equals(' ')) k++;
            }
            Console.WriteLine(text.Length);
            char[] words1 = new char[text.Length];
            for (i = text.Length - 1; i >=0 ; i--)
            {
                if (i == text.Length-1 || text[i+1].Equals(' ')) start = i;
                if (text[i].Equals(' ')||i==0)
                {
                    for (j = i; j <= start; j++)
                    {
                        if (text[j].Equals(' ')) j++;
                        words1[l] = text[j];
                        l++;
                    }
                    if (i != 0)
                    {
                        words1[l] = ' ';
                        l++;
                    }
                }
            }
            Console.WriteLine(words1); 
        }
    }
}
