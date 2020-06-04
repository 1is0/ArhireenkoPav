using System;
using System.Collections.Generic;
using System.Text;

namespace Lab6
{
    abstract class Production : JewerelyStore, IComparer, IAction
    {
        public enum OrderTypes
        {
            SmallShopS = 1,
            SmallShopP,
            SmallShopG,
            MediumShopS,
            MediumShopP,
            MediumShopG,
            CorporationS,
            CorporationP,
            CorporationG
        }
        public enum Style
        {
            Usual = 1,
            Evening,
            Bright
        }
        public Production()
            : base()
        { }
        public Production(OrderTypes new_order)
            : base()
        {
            switch (new_order)
            {
                case OrderTypes.SmallShopS:
                    this.Material = 1;
                    this.Mass = 100;
                    this.Count = 5;
                    break;
                case OrderTypes.SmallShopP:
                    this.Material = 2;
                    this.Mass = 100;
                    this.Count = 5;
                    break;
                case OrderTypes.SmallShopG:
                    this.Material = 3;
                    this.Mass = 100;
                    this.Count = 5;
                    break;
                case OrderTypes.MediumShopS:
                    this.Material = 1;
                    this.Mass = 200;
                    this.Count = 15;
                    break;
                case OrderTypes.MediumShopP:
                    this.Material = 2;
                    this.Mass = 200;
                    this.Count = 15;
                    break;
                case OrderTypes.MediumShopG:
                    this.Material = 3;
                    this.Mass = 200;
                    this.Count = 15;
                    break;
                case OrderTypes.CorporationS:
                    this.Material = 1;
                    this.Mass = 300;
                    this.Count = 40;
                    break;
                case OrderTypes.CorporationP:
                    this.Material = 2;
                    this.Mass = 300;
                    this.Count = 40;
                    break;
                case OrderTypes.CorporationG:
                    this.Material = 3;
                    this.Mass = 300;
                    this.Count = 40;
                    break;
            }
        }
        public Production(int new_material, double new_mass, int new_count)
            : base(new_material, new_mass, new_count)
        { }
        public abstract void ShowSpecialization();
        public struct Passport
        {
            int Сontent;
            string Data;
            string Jew;
            public Passport(int content, string data, string jew)
            {
                Random cr = new Random();
                this.Сontent = cr.Next(content, content + 100);
                this.Data = data;
                this.Jew = jew;
            }
            public void ShowPassport()
            {
                Console.WriteLine($"Проба металла:{this.Сontent}");
                Console.WriteLine($"Дата производства:{this.Data}");
                Console.WriteLine($"Производитель:{this.Jew}");
            }
        }

        public int Compare(Production prod2)
        {
            if (this.ordercost > prod2.ordercost)
                return 1;
            else if (this.ordercost < prod2.ordercost)
                return -1;
            else return 0;
        }
        public void Up(Production prod1)
        {
            prod1.Count *= 2;
        }

    }
}
