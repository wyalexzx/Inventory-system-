using UnityEngine;

public class ItemPickup : MonoBehaviour
{
    public Item item;  // The item this pickup represents
    public Inventory inventory;  // Reference to the player's inventory

    void OnTriggerEnter(Collider other)
    {
        // If the player collides with the item, add it to the inventory
        if (other.CompareTag("Player"))
        {
            inventory.AddItem(item);
            Destroy(gameObject);  // Destroy the item in the world
              }
       }
}
