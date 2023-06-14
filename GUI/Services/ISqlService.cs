using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GUI.Services
{
    public interface ISqlService<T> where T : class
    {
        int Add(T t);
        int Add(params T[] t);
        int Update(T t);
        int Update(params T[] t);
        int Delete(T t);
        int Delete(params T[] t);
        T Select(string Id);
        List<T> Select();
        List<T> Select(params string[] Ids);
    }
}
