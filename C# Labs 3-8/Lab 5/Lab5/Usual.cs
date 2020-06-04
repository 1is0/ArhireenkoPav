using System;
using System.Collections.Generic;
using System.Text;

namespace Lab5
{
    class Usual : Production
    {
        public Usual()
            : base()
        {

        }
        public Usual(OrderTypes new_order)
            : base(new_order)
        {

        }
        public override void ShowSpecialization()
        {
            Console.WriteLine("Заказ на повседневный стиль.");
        }
        public override void Output()
        {
            this.ShowSpecialization();
            Passport pass1 = new Passport(900, "12.07.2019", "JewOptCorp");
            pass1.ShowPassport();
            base.Output();
        }
    }
}
