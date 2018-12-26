using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DataAccessLayer;
using DataAccessLayer.Modelo;

namespace BusinessLogic
{
    public class OrderLogic
    {
        OrderDAL dataAccess = new OrderDAL();
        public List<Order> GetOrderList()
        {
            var orders = dataAccess.GetOrderList();
            return orders;
        }

        public List<Order_Item> GetOrder_ItemList()
        {
            var orders = dataAccess.GetOrder_ItemList();
            return orders;
        }

        public void CreateNewOrder(Order newOrder)
        {
            dataAccess.CreateNewOrder(newOrder);
        }

        public void CreateNewOrderItem(Order_Item newOrder)
        {
            dataAccess.CreateNewOrderItem(newOrder);
        }

        public Order GetOrderByID(string id)
        {
            Order order = dataAccess.GetOrderByID(id);
            return order;
        }

        public Order_Item GetOrderItemByID(int id)
        {
            Order_Item order = dataAccess.GetOrderItemByID(id);
            return order;
        }
        public void UpdateOrder(Order order)
        {
            dataAccess.UpdateOrder(order);
        }
        public void UpdateOrderItem(Order_Item order)
        {
            dataAccess.UpdateOrderItem(order);
        }
        public void DeleteOrderByID(string id)
        {
            dataAccess.DeleteOrderByID(id);
        }
        public void DeleteOrderItemByID(int id)
        {
            dataAccess.DeleteOrderItemByID(id);
        }
    }
}
