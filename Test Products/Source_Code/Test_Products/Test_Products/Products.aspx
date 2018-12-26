<%@ Page Title="Products" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Products.aspx.cs" Inherits="Test_Products.Products" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
    <h2><%: Title %>.</h2>
    
    <div class="top-button">
        <asp:Button ID="AddNewBtn" runat="server" Text="Add New" OnClick="AddNewBtn_Click" class="btn btn-primary btn-info" />
    </div>
    <br />
    
    <div class="main-data" id="divGridView" runat="server" style="height: 175px">
        <asp:GridView ID="ProductGridView" runat="server" AutoGenerateColumns="False" Width="949px" Height="85px" OnRowCommand="ProductGridView_RowCommand" class="table table-bordered bs-table" AllowPaging="True" OnPageIndexChanging="ProductGridView_PageIndexChanging" PageSize="5">
            <PagerStyle VerticalAlign="Bottom" HorizontalAlign="Right"/>
            <HeaderStyle BackColor="#337ab7" Font-Bold="True" ForeColor="White" />
            <EditRowStyle BackColor="#ffffcc" />
            <Columns>
                <asp:BoundField DataField="Product_ID" HeaderText="Product ID" HeaderStyle-Width="90px" />
                <asp:BoundField DataField="Category" HeaderText="Category" />
                <asp:BoundField DataField="Product_Name" HeaderText="Product name" />
                <asp:BoundField DataField="Price" HeaderText="Price" />
                <asp:BoundField DataField="Description" HeaderText="Description" />
                <asp:BoundField DataField="Creation_Date" HeaderText="Date of creation" DataFormatString="{0:dd-M-yyyy}" />
                <asp:TemplateField HeaderText="Edit">
                    <ItemTemplate>
                        <asp:ImageButton ID="EditBtn" runat="server" CommandArgument='<%# Eval("Product_ID") %>' CommandName="_edit" Height="16px" ImageUrl="~/Images/Brush.png" Width="16px" />
                    </ItemTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Delete">
                    <ItemTemplate>
                        <asp:ImageButton ID="DeleteBtn" runat="server" CommandArgument='<%# Eval("Product_ID") %>' CommandName="_delete" Height="16px" ImageUrl="~/Images/Cancel.png" Width="16px" OnClientClick="return confirm('Are you sure that you want to delete this product?');" />
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
                    <td text-align: right id="td_productid">Product ID</td>
                    <td>
                        <asp:TextBox ID="txtProductId" runat="server" Width="380px" TextMode="Number"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td text-align: right>Category</td>
                    <td>
                        <asp:DropDownList ID="txtCategoryDropDown" runat="server" Width="380px" OnSelectedIndexChanged="DropDownSelectedIndexChanged">
                            <asp:ListItem Value="TOYS"></asp:ListItem>
                            <asp:ListItem Value="TECH"></asp:ListItem>
                            <asp:ListItem Value="CLOTHES"></asp:ListItem>
                            <asp:ListItem Value="SHOES"></asp:ListItem>
                            <asp:ListItem Value="TRAVEL"></asp:ListItem>
                        </asp:DropDownList>
                        <asp:TextBox ID="txtCategory" runat="server" Visible="False" />
                        <%--<asp:TextBox ID="txtCategory" runat="server" Width="380px"></asp:TextBox>--%>
                    </td>
                </tr>
                <tr>
                    <td text-align: right style="height: 20px">Name</td>
                    <td style="height: 20px">
                        <asp:TextBox ID="txtName" runat="server" Width="380px"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td text-align: right>Price</td>
                    <td>
                        <asp:TextBox ID="txtPrice" runat="server" Width="380px"></asp:TextBox>
                        <asp:RegularExpressionValidator id="RegularExpressionValidator1" 
                         ControlToValidate="txtPrice"
                         ValidationExpression="^([0-9]{1,18})([,][0-9]{1,2})?$"
                         Display="Dynamic"
                         ErrorMessage="Only decimal numbers."
                         runat="server"/>
                    </td>
                </tr>
                <tr>
                    <td text-align: right>Description</td>
                    <td>
                        <asp:TextBox ID="txtDescription" runat="server" Width="380px"></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td text-align: right>Date</td>
                    <td>
                        <asp:TextBox ID="txtDate" runat="server" Width="380px" TextMode="Date"></asp:TextBox>
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
    &nbsp;<asp:HiddenField ID="HiddenField_value" runat="server" />
    <asp:Label ID="IbIDisplay" runat="server" ForeColor="Red" Visible="False"></asp:Label>
    <br />
    <br />
    <br />
    <br />
    <br />
    <br />
    <br />
    <br />
    <br />
    <br />
    <br />
    <br />
</asp:Content>
