<%@ Page Title="Orders" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Orders.aspx.cs" Inherits="Test_Products.Orders" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
    <h2><%: Title %>.</h2>

    <div class="top-button">
        <asp:Button ID="AddNewBtn" runat="server" Text="Add New" OnClick="AddNewBtn_Click" class="btn btn-primary btn-info" />
    </div>
    <br />
    
    <div class="main-data" id="divGridView" runat="server" style="height: 175px">
        <asp:GridView ID="OrderGridView" runat="server" AutoGenerateColumns="False" Width="949px" Height="85px" OnRowCommand="OrderGridView_RowCommand" class="table table-bordered bs-table" AllowPaging="True" OnPageIndexChanging="OrderGridView_PageIndexChanging" PageSize="5" >
            <PagerStyle VerticalAlign="Bottom" HorizontalAlign="Right"/>
            <HeaderStyle BackColor="#337ab7" Font-Bold="True" ForeColor="White"/>
            <EditRowStyle BackColor="#ffffcc" />
            <Columns>
                <asp:BoundField DataField="Order_ID" HeaderText="Order ID" HeaderStyle-Width="80px" HeaderStyle-HorizontalAlign="Center" />
                <asp:BoundField DataField="Order_Date" HeaderText="Date" DataFormatString="{0:dd-M-yyyy}" />
                <asp:BoundField DataField="Status" HeaderText="Status" />
                <asp:TemplateField HeaderText="Edit"  HeaderStyle-Width="30px">
                    <ItemTemplate>
                        <asp:ImageButton ID="EditBtn" runat="server" CommandArgument='<%# Eval("Order_ID") %>' CommandName="_edit" Height="16px" ImageUrl="~/Images/Brush.png" Width="16px" />
                    </ItemTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Delete" HeaderStyle-Width="50px">
                    <ItemTemplate>
                        <asp:ImageButton ID="DeleteBtn" runat="server" CommandArgument='<%# Eval("Order_ID") %>' CommandName="_delete" Height="16px" ImageUrl="~/Images/Cancel.png" Width="16px" OnClientClick="return confirm('Are you sure that you want to delete this order?');" />
                    </ItemTemplate>
                </asp:TemplateField>
            </Columns>
            <HeaderStyle HorizontalAlign="Center" VerticalAlign="Middle" Width="5px" />

        </asp:GridView>
    </div>
    <br />
    <div id="divAddEdit" runat="server">
         <table class="table table-striped table-hover" style="width: 45%; border: 1px solid #000000; height: 217px;">
            <thead>
                <tr>
                    <th text-align: center colspan="2" style="text-align: center">Add/Edit Form</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td text-align: right id="td_orderid">Order ID</td>
                    <td>
                        <asp:TextBox ID="txtOrderId" runat="server" Width="380px"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td text-align: right>Order Date</td>
                    <td>
                        <asp:TextBox ID="txtOrderDate" runat="server" Width="380px" TextMode="Date"></asp:TextBox>
                    </td>
                </tr>
                 <tr>
                    <td text-align: right>Status</td>
                    <td>
                        <asp:DropDownList ID="txtStatusDropDown" runat="server" Width="380px" OnSelectedIndexChanged="DropDownSelectedIndexChanged">
                            <asp:ListItem Value="APPROVED"></asp:ListItem>
                            <asp:ListItem Value="PENDING"></asp:ListItem>
                            <asp:ListItem Value="CLOSED"></asp:ListItem>
                            <asp:ListItem Value="OPEN"></asp:ListItem>
                        </asp:DropDownList>
                        <asp:TextBox ID="txtStatus" runat="server" Visible="False" />
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>
                        <asp:Button ID="SaveBtn" runat="server" OnClick="SaveBtn_Click" Text="Save" Width="70px" class="btn btn-primary btn-info"/>
                        <asp:Button ID="CancelBtn" runat="server" OnClick="CancelBtn_Click" Text="Cancel" class="btn btn-primary btn-danger" Width="70px"/>
                    </td>
                </tr>
            </tbody>
         </table>
    </div>

    <div id="EditOrderDetails" runat="server">
         <table class="table table-striped table-hover" style="width: 45%; border: 1px solid #000000; height: 217px;">
            <thead>
                <tr>
                    <th text-align: center colspan="2" style="text-align: center">Add/Edit Order Items Form</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td text-align: right id="td_orderCode">Order ID</td>
                    <td>
                        <asp:TextBox ID="txtOrderCode" runat="server" Width="380px"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td text-align: right id="td_orderitemid">Order Item ID</td>
                    <td>
                        <asp:TextBox ID="txtOrderItem" runat="server" Width="380px"></asp:TextBox>
                    </td>
                </tr>
                 <tr>
                    <td text-align: right>Product</td>
                    <td>
                        <asp:DropDownList ID="DropDownList2" runat="server" Width="380px" OnSelectedIndexChanged="DropDownSelectedIndexChanged_Product">
                            <asp:ListItem Value="APPROVED"></asp:ListItem>
                            <asp:ListItem Value="PENDING"></asp:ListItem>
                            <asp:ListItem Value="CLOSED"></asp:ListItem>
                            <asp:ListItem Value="OPEN"></asp:ListItem>
                        </asp:DropDownList>
                        <asp:TextBox ID="txtProduct" runat="server" Visible="False" />
                    </td>
                </tr>
                <tr>
                    <td text-align: right>Product Name</td>
                    <td>
                        <asp:TextBox ID="txtProductName" runat="server" Width="380px"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td text-align: right>Quantity</td>
                    <td>
                        <asp:TextBox ID="txtQuantity" runat="server" Width="380px"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td text-align: right>Total Amount</td>
                    <td>
                        <asp:TextBox ID="txtTotal_Amount" runat="server" Width="380px"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>
                        <asp:Button ID="SaveOrderBtn" runat="server" OnClick="SaveBtn_Click" Text="Save" Width="70px" class="btn btn-primary btn-info"/>
                        <asp:Button ID="CancelOrderBtn" runat="server" OnClick="CancelBtn_Click" Text="Cancel" class="btn btn-primary btn-danger" Width="70px"/>
                    </td>
                </tr>
            </tbody>
         </table>
    </div>
    &nbsp;<asp:HiddenField ID="HiddenField_value" runat="server" />
    <asp:Label ID="IbIDisplay" runat="server" ForeColor="Red" Visible="False"></asp:Label>
    <br />
    <br />
    <br />
    <br />
    <br />
    <br />
</asp:Content>
