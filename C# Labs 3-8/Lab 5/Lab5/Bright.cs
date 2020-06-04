using System;
using System.Collections.Generic;
using System.Text;

namespace Lab5
{
    class Bright : Production
    {
        public Bright(OrderTypes new_order)
            : base(new_order)
        {

        }
        public override void ShowSpecialization()
        {
            Console.WriteLine("Заказ на фирменный стиль.");
        }
        public override void Output()
        {
            this.ShowSpecialization();
            Passport pass1 = new Passport(900, "18.03.2018", "JewOptCorp");
            pass1.ShowPassport();
            base.Output();
        }
    }
}
