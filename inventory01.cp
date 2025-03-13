using System.Collections.Generic;
using UnityEngine;

public class Inventory : MonoBehaviour
{
    // A list to hold the items in the inventory
    public List<Item> items = new List<Item>();
    
    // The maximum size of the inventory
    public int inventorySize = 20;

    // The UI object that will display the inventory
    public Transform inventoryUI;
    
    // The inventory slot prefab
    public GameObject slotPrefab;

    private void Start()
    {
        // Initialize the inventory UI
        UpdateInventoryUI();
    }

    public void AddItem(Item item)
    {
        // Check if inventory is full
        if (items.Count < inventorySize)
        {
            items.Add(item);
            UpdateInventoryUI();
        }
        else
        {
            Debug.Log("Inventory is full!");
        }
    }

    public void RemoveItem(Item item)
    {
        if (items.Contains(item))
        {
            items.Remove(item);
            UpdateInventoryUI();
        }
    }

    private void UpdateInventoryUI()
    {
        // Clear previous UI elements
        foreach (Transform child in inventoryUI)
        {
            Destroy(child.gameObject);
        }

        // Create a new UI slot for each item
        foreach (Item item in items)
        {
            GameObject slot = Instantiate(slotPrefab, inventoryUI);
            // Set the item details in the slot (you can customize how to display)
            slot.GetComponentInChildren<UnityEngine.UI.Text>().text = item.itemName;
        }
    }
}

[System.Serializable]
public class Item
{
    public string itemName;
    public Sprite itemIcon;
}
