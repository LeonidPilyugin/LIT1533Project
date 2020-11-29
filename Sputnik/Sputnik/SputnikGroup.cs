using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sputnik
{
    public class SputnikGroup : TypeInList
    {
        public enum TypeOfGroup { Trawl, Web, Other, No }
        public SputnikGroup()
        {
            SputnikList = new List<TypeInList>();
            Type = TypeOfGroup.No;
        }

        public SputnikGroup(TypeOfGroup Type)
        {
            SputnikList = new List<TypeInList>();
            this.Type = Type;
        }
        public List<TypeInList> SputnikList//список спутников
        {
            get;
        }
        public TypeOfGroup Type//тип группы
        {
            get; set;
        }
        public void Add(TypeInList sputnikgroup)//добавить элемент
        {
            SputnikList.Add(sputnikgroup);
        }
        public void Clear()//удалить все элементы
        {
            SputnikList.Clear();
        }
        public void Remove(TypeInList sputnikgroup)//удалить элемент
        {
            SputnikList.Remove(sputnikgroup);
        }
    }
}
