using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DataAccessLayer;
using DataAccessLayer.Modelo;

namespace BusinessLogic
{
    public class ProductLogic
    {
        ProductDAL dataAccess = new ProductDAL();
        public List<Product> GetProductList()
        {
            var products = dataAccess.GetProductList();
            return products;
        }

        public void CreateNewProduct(Product newProduct)
        {
            dataAccess.CreateNewProduct(newProduct);
        }

        public Product GetProductByID(int id)
        {
            Product product = dataAccess.GetProductByID(id);
            return product;
        }

        public void UpdateProduct(Product product)
        {
            dataAccess.UpdateProduct(product);
        }

        public void DeleteProductByID(int id)
        {
            dataAccess.DeleteProductByID(id);
        }
    }
}
