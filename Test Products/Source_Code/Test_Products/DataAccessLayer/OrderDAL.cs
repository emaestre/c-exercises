using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DataAccessLayer.Modelo;

namespace DataAccessLayer
{
    public class OrderDAL
    {
        TestProductDBEntities dataBase = new TestProductDBEntities();

        public List<Order> GetOrderList()
        {
            var orders = dataBase.Order.ToList();
            return orders;
        }

        public List<Order_Item> GetOrder_ItemList()
        {
            var ordersItem = dataBase.Order_Item.ToList();
            return ordersItem;
        }

        public void CreateNewOrder(Order newOrder)
        {
            dataBase.Order.Add(newOrder);
            dataBase.SaveChanges();
        }

        public void CreateNewOrderItem(Order_Item newOrderItem)
        {
            dataBase.Order_Item.Add(newOrderItem);
            dataBase.SaveChanges();
        }

        public Order GetOrderByID(string id)
        {
            Order order = dataBase.Order.Find(id);
            return order;
        }

        public Order_Item GetOrderItemByID(int id)
        {
            Order_Item orderItem = dataBase.Order_Item.Find(id);
            return orderItem;
        }

        public void UpdateOrder(Order order)
        {
            dataBase.Entry(order).State = System.Data.Entity.EntityState.Modified;
            dataBase.SaveChanges();
        }

        public void UpdateOrderItem(Order_Item orderItem)
        {
            dataBase.Entry(orderItem).State = System.Data.Entity.EntityState.Modified;
            dataBase.SaveChanges();
        }

        public void DeleteOrderByID(string id)
        {
            var order = dataBase.Order.Find(id);
            dataBase.Order.Remove(order);
            dataBase.SaveChanges();
        }
        public void DeleteOrderItemByID(int id)
        {
            var orderItem = dataBase.Order_Item.Find(id);
            dataBase.Order_Item.Remove(orderItem);
            dataBase.SaveChanges();
        }
    }
}
