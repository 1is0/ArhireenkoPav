using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace UnusualPlayer1
{
    class UnusualPlayer : IDisposable
    {
        [DllImport("winmm.dll")]
        private static extern long mciSendString(string strCommand, StringBuilder strReturn, int iReturnLength, IntPtr hwndCallback);

        public UnusualPlayer(string fileName)
        {
            const string form = @"open ""{0}"" type mpegvideo alias MediaFile";
            string Command = String.Format(form, fileName);
            mciSendString(Command, null, 0, IntPtr.Zero);
        }
        public void Play()
        {
            string Command = "play MediaFile";
            mciSendString(Command, null, 0, IntPtr.Zero);
        }
        public void Dispose()
        {
            string Command = "close MediaFile";
            mciSendString(Command, null, 0, IntPtr.Zero);
        }
    }
}
