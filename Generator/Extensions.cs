using System;
using System.Collections.ObjectModel;

namespace Generator {
	public static class Extensions {
		public static TItem Find<TKey, TItem>(this KeyedCollection<TKey, TItem> keyedCollection, Predicate<TItem> match) {
			if (match == null) {
				throw new ArgumentNullException();
			}

			foreach (var item in keyedCollection) {
				if (match(item)) {
					return item;
				}
			}

			return default;
		}
	}
}
