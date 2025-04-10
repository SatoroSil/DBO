using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Babidi
{
    // ��ġ �Լ�
    public delegate bool SearchDelegate( string strSearch, Boolean bFirst);

    public partial class Find : Form
    {
        public SearchDelegate m_delSearch = null;
        
        public Find()
        {
            InitializeComponent();
        }

        public Find(SearchDelegate delSearch)
        {
            m_delSearch = delSearch;

            InitializeComponent();

        }

        private void btnNextSearch_Click(object sender, EventArgs e)
        {
            if (m_delSearch == null)
            {
                MessageBox.Show("�˻� Delegate�� ã�� ���߽��ϴ�: Babidi �����Դϴ�. ����ڿ��� �����ϼ���.");
                return;
            }

            if (!m_delSearch(this.m_textSearch.Text, false))
            {
                MessageBox.Show("���� ���õ� Cell�� Column���� �ش� ������ ã�� ���߽��ϴ�.");

                //if (DialogResult.OK == MessageBox.Show("���� ���õ� Cell�� Column���� �ش� ������ ã�� ���߽��ϴ�. ó������ �ٽ� ã���ðڽ��ϱ�?"))
                //{
                //    if (!m_delSearch(this.m_textSearch.Text, true))
                //    {
                //        MessageBox.Show("���� ���õ� Cell�� Column���� �ش� ������ ã�� ���߽��ϴ�.");
                //    }
                //}
            }

            this.Focus();
        }

        private void m_textSearch_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                btnNextSearch_Click(null, null);
            }
            else if (e.KeyCode == Keys.Escape)
            {
                Close();
            }
        }
    }
}