using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using BusinessLogic;

namespace Test_Products
{
    public partial class Products : System.Web.UI.Page
    {
        ProductLogic logicData = new ProductLogic();
        protected void Page_Load(object sender, EventArgs e)
        {
            if(!IsPostBack)
            {
                BindingProductData();
                divAddEdit.Visible = false;
            }
        }

        private void BindingProductData()
        {
            try
            {
                List<DataAccessLayer.Modelo.Product> listProduct = logicData.GetProductList();
                ProductGridView.DataSource = listProduct;
                ProductGridView.DataBind();
            }
            catch(Exception)
            {
                throw;
            }
        }

        protected void AddNewBtn_Click(object sender, EventArgs e)
        {
            divAddEdit.Visible = true;
            txtProductId.Visible = true;
            divGridView.Visible = false;
        }

        protected void SaveBtn_Click(object sender, EventArgs e)
        {
            if(IsValid)
            {
                if(HiddenField_value.Value == string.Empty)
                {
                    InsertProduct();
                }
                else
                {
                    UpdateProduct();
                }
                ResetForm();
                BindingProductData();
            }
        }

        private void UpdateProduct()
        {
            try
            {
                var productToInsert = txtProductId.Text.ToString();
                var productCategory = txtCategory.Text.ToString();
                var productName = txtName.Text.ToString();
                var productPrice = txtPrice.Text.ToString();
                var productDescription = txtDescription.Text.ToString();
                var productDate = txtDate.Text.ToString();
                var prod = new DataAccessLayer.Modelo.Product();
                prod.Product_ID = int.Parse(productToInsert);
                prod.Category = productCategory;
                prod.Product_Name = productName;
                prod.Price = decimal.Parse(productPrice);
                prod.Description = productDescription;
                prod.Creation_Date = DateTime.Parse(productDate);
                logicData.UpdateProduct(prod);
            }
            catch (Exception ex)
            {
                IbIDisplay.Visible = true;
                IbIDisplay.Text = ex.Message;
            }
        }

        private void InsertProduct()
        {
            try
            {
                var productToInsert = txtProductId.Text.ToString();
                var productCategory = txtCategory.Text.ToString();
                var productName = txtName.Text.ToString();
                var productPrice = txtPrice.Text.ToString();
                var productDescription = txtDescription.Text.ToString();
                var productDate = txtDate.Text.ToString();
                var prod = new DataAccessLayer.Modelo.Product();
                prod.Product_ID = int.Parse(productToInsert);
                prod.Category = productCategory;
                prod.Product_Name = productName;
                prod.Price = decimal.Parse(productPrice);
                prod.Description = productDescription;
                prod.Creation_Date = DateTime.Parse(productDate);
                if(logicData.GetProductByID(prod.Product_ID) != null)
                {
                    Response.Write("<script>alert('Already exists a product with that ID!');</script>");
                }
                else
                {
                    logicData.CreateNewProduct(prod);
                }
            }
            catch (Exception ex)
            {
                IbIDisplay.Visible = true;
                IbIDisplay.Text = ex.Message;
            }
        }
        protected void CancelBtn_Click(object sender, EventArgs e)
        {
            ResetForm();
        }

        private void ResetForm()
        {
            txtProductId.Text = string.Empty;
            txtCategory.Text = string.Empty;
            txtName.Text = string.Empty;
            txtPrice.Text = string.Empty;
            txtDescription.Text = string.Empty;
            txtDate.Text = string.Empty;
            divAddEdit.Visible = false;
            divGridView.Visible = true;
            HiddenField_value.Value = string.Empty;
            IbIDisplay.Visible = false;
        }

        protected void ProductGridView_RowCommand(object sender, GridViewCommandEventArgs e)
        {
            string strID = e.CommandArgument.ToString();
            string strName = e.CommandName.ToLower();
            switch(strName)
            {
                case "_edit":
                    divAddEdit.Visible = true;
                    txtProductId.Visible = false;
                    divGridView.Visible = false;
                    HiddenField_value.Value = strID;
                    LoadDataToEdit();
                    break;
                case "_delete":
                    try
                    {
                        logicData.DeleteProductByID(Convert.ToInt32(strID));
                        IbIDisplay.Visible = false;
                        BindingProductData();
                    }
                    catch (Exception)
                    {
                        IbIDisplay.Visible = true;
                        IbIDisplay.Text = "You can not delete this product!";
                    }
                    break;
            }
        }

        public void ProductGridView_PageIndexChanging(object sender, GridViewPageEventArgs e)
        {
            ProductGridView.PageIndex = e.NewPageIndex;
            BindingProductData();
        }

        private void LoadDataToEdit()
        {
            try
            {
                var dataLoad = logicData.GetProductByID(Convert.ToInt32(HiddenField_value.Value));
                txtProductId.Text = dataLoad.Product_ID.ToString();
                txtCategory.Text = dataLoad.Category;
                txtName.Text = dataLoad.Product_Name;
                txtPrice.Text = dataLoad.Price.ToString();
                txtDescription.Text = dataLoad.Description;
                txtDate.Text = dataLoad.Creation_Date.ToString();
            }
            catch (Exception exe)
            {
                IbIDisplay.Visible = true;
                IbIDisplay.Text = exe.Message;
                return;
            }
        }

        public void DropDownSelectedIndexChanged(object sender, EventArgs e)
        {
            DropDownList dropDownList = (DropDownList)sender;
            txtCategory.Enabled = false;
            txtCategory.Text = dropDownList.SelectedValue;
        }
    }
}