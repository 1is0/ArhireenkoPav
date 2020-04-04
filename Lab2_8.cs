using System;
using System.Text;
using System.Globalization;

namespace Example
{
    class Lab2_8
    {

        static void Main()
        {
            string h = "fr-FR";  //"de-DE", "en-US", "es-ES", "fr-FR"
            for (int i = 1; i <= 12; i++)
            {
                DateTime date1 = new DateTime(2015, i, 20);
                Console.WriteLine(date1.ToString("MMMM", CultureInfo.CreateSpecificCulture(h)));
            }
        }
    }
}

//https://docs.microsoft.com/en-us/dotnet/api/system.datetime.tostring?view=netframework-4.8
