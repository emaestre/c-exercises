using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using BusinessLogic;

namespace Test_Products
{
    public partial class Orders : System.Web.UI.Page
    {
        OrderLogic logicData = new OrderLogic();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                BindingOrderData();
                divAddEdit.Visible = false;
                EditOrderDetails.Visible = false;
            }
        }

        private void BindingOrderData()
        {
            try
            {
                List<DataAccessLayer.Modelo.Order> listOrder = logicData.GetOrderList();
                OrderGridView.DataSource = listOrder;
                OrderGridView.DataBind();
            }
            catch (Exception)
            {
                throw;
            }
        }

        protected void AddNewBtn_Click(object sender, EventArgs e)
        {
            divAddEdit.Visible = true;
            txtOrderId.Visible = true;
            divGridView.Visible = false;
        }

        protected void SaveBtn_Click(object sender, EventArgs e)
        {
            if (IsValid)
            {
                if (HiddenField_value.Value == string.Empty)
                {
                    InsertOrder();
                    EditOrderDetails.Visible = true;
                    divGridView.Visible = false;
                    InsertOrderDetails();
                }
                else
                {
                    UpdateOrder();
                }
                ResetForm();
                BindingOrderData();
            }
        }

        private void UpdateOrder()
        {
            try
            {
                var orderId = txtOrderId.Text.ToString();
                var orderDate = txtOrderDate.Text.ToString();
                var orderStatus = txtStatus.Text.ToString();
                var order = new DataAccessLayer.Modelo.Order();
                order.Order_ID = orderId;
                order.Order_Date = DateTime.Parse(orderDate);
                order.Status = orderStatus;
                logicData.UpdateOrder(order);
            }
            catch (Exception ex)
            {
                IbIDisplay.Visible = true;
                IbIDisplay.Text = ex.Message;
            }
        }

        private void InsertOrder()
        {
            try
            {
                var orderId = txtOrderId.Text.ToString();
                var orderDate = txtOrderDate.Text.ToString();
                var orderStatus = txtStatus.Text.ToString();
                var order = new DataAccessLayer.Modelo.Order();
                order.Order_ID = orderId;
                order.Order_Date = DateTime.Parse(orderDate);
                order.Status = orderStatus;
                if (logicData.GetOrderByID(order.Order_ID) != null)
                {
                    Response.Write("<script>alert('Already exists a order with that ID!');</script>");
                }
                else
                {
                    logicData.CreateNewOrder(order);
                }
            }
            catch (Exception ex)
            {
                IbIDisplay.Visible = true;
                IbIDisplay.Text = ex.Message;
            }
        }

        private void InsertOrderDetails()
        {
            try
            {
                var orderCode = txtOrderId.Text.ToString();
                var orderItemId = txtOrderItem.Text.ToString();
                var orderProduct = txtProduct.Text.ToString();
                var orderProductName = txtProductName.Text.ToString();
                var orderQuantity = txtQuantity.Text.ToString();
                var order = new DataAccessLayer.Modelo.Order_Item();
                order.Order_ID = orderCode;
                order.Detail_ID = int.Parse(orderItemId);
                order.Product_ID = int.Parse(orderProduct);
                order.Product_Name = orderProductName;
                order.Quantity = int.Parse(orderQuantity);
                //order.Total_Amount = decimal.Parse()
                logicData.CreateNewOrderItem(order);
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
            txtOrderId.Text = string.Empty;
            txtStatus.Text = string.Empty;
            txtOrderDate.Text = string.Empty;
            divAddEdit.Visible = false;
            divGridView.Visible = true;
            HiddenField_value.Value = string.Empty;
            IbIDisplay.Visible = false;
        }

        protected void OrderGridView_RowCommand(object sender, GridViewCommandEventArgs e)
        {
            string strID = e.CommandArgument.ToString();
            string strName = e.CommandName.ToLower();
            switch (strName)
            {
                case "_edit":
                    divAddEdit.Visible = true;
                    txtOrderId.Visible = false;
                    divGridView.Visible = false;
                    HiddenField_value.Value = strID;
                    LoadDataToEdit();
                    break;
                case "_delete":
                    try
                    {
                        logicData.DeleteOrderByID(strID);
                        IbIDisplay.Visible = false;
                        BindingOrderData();
                    }
                    catch (Exception)
                    {
                        IbIDisplay.Visible = true;
                        IbIDisplay.Text = "You can not delete this order!";
                    }
                    break;
            }
        }

        public void OrderGridView_PageIndexChanging(object sender, GridViewPageEventArgs e)
        {
            OrderGridView.PageIndex = e.NewPageIndex;
            BindingOrderData();
        }

        private void LoadDataToEdit()
        {
            try
            {
                var dataLoad = logicData.GetOrderByID(HiddenField_value.Value);
                txtOrderId.Text = dataLoad.Order_ID;
                txtOrderDate.Text = dataLoad.Order_Date.ToString();
                txtStatus.Text = dataLoad.Status;
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
            txtStatus.Enabled = false;
            txtStatus.Text = dropDownList.SelectedValue;
        }

        public void DropDownSelectedIndexChanged_Product(object sender, EventArgs e)
        {
            DropDownList dropDownList = (DropDownList)sender;
            txtProduct.Enabled = false;
            txtProduct.Text = dropDownList.SelectedValue;
        }
    }
}