using System;
using System.Collections.Generic;
using System.Text;

namespace Lab8
{
    class Evening : Production
    {
        public Evening(OrderTypes new_order)
            : base(new_order)
        {

        }
        public override void ShowSpecialization()
        {
            Console.WriteLine("Заказ на вечерний стиль.");
        }
        public override void Output()
        {
            this.ShowSpecialization();
            Passport pass1 = new Passport(900, "01.06.2017", "JewOptCorp");
            pass1.ShowPassport();
            base.Output();
        }
    }
}
