using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UnusualPlayer1
{
    public partial class Form1 : Form
    {
        private UnusualPlayer _player;
        public Form1()
        {
          InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog file1 = new OpenFileDialog())
            {
                file1.Filter = "Mp3 File|*.mp3";
                file1.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyMusic);

                if (file1.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    _player = new UnusualPlayer(file1.FileName);
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (_player != null)
                _player.Play();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (_player != null)
                _player.Dispose();
        }
    }
}
