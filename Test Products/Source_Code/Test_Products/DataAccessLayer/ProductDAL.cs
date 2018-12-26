using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DataAccessLayer.Modelo;

namespace DataAccessLayer
{
    public class ProductDAL
    {
        TestProductDBEntities dataBase = new TestProductDBEntities();

        public List<Product> GetProductList()
        {
            var products = dataBase.Product.ToList();
            return products;
        }

        public void CreateNewProduct(Product newProduct)
        {
            dataBase.Product.Add(newProduct);
            dataBase.SaveChanges();
        }

        public Product GetProductByID(int id)
        {
            Product product = dataBase.Product.Find(id);
            return product;
        }

        public void UpdateProduct(Product product)
        {
            dataBase.Entry(product).State = System.Data.Entity.EntityState.Modified;
            dataBase.SaveChanges();
        }

        public void DeleteProductByID(int id)
        {
            var product = dataBase.Product.Find(id);
            dataBase.Product.Remove(product);
            dataBase.SaveChanges();
        }
    }
}
