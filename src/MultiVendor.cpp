/*
 *MIT License
 *
 *Copyright (c) 2022 Azerothcore & WoWHellgarve
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy
 *of this software and associated documentation files (the "Software"), to deal
 *in the Software without restriction, including without limitation the rights
 *to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *copies of the Software, and to permit persons to whom the Software is
 *furnished to do so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all
 *copies or substantial portions of the Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *SOFTWARE.
 *
 * Multi-Vendor Module
 * Original Module From WoWHellgarve 
 * Written for Azerothcore & WoWHellgarve 335 By Developer HolyDEEW
 * Modified for Azerothcore
 */

#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"


/*-- DATA NPC_TEMPLATE
SET
@NpcEntry 		:= 666666
@NpcName		:= "Multi-Vendor"
@NpcSubname		:= "WoWHellgarve Vendor"
@NpcDisplayID   := 1298
*/

//277_284-------------------------------------
#define GOSSIP_TEXT_BROWSE_WEAPONS_277_284      "|TInterface/ICONS/Inv_mace_116:24:24:-18|t[Let me browse your Weapons]"
#define GOSSIP_TEXT_BROWSE_ARMOR_277_284        "|TInterface/ICONS/inv_chest_cloth_04:24:24:-18|t[Show me T10,5 Armor]"
#define GOSSIP_TEXT_BROWSE_ACCESSORIES_277_284  "|TInterface/ICONS/inv_chest_cloth_04:24:24:-18|t[Show me off set pieces]"
//264-------------------------------------
#define GOSSIP_TEXT_BROWSE_WEAPONS_264          "|TInterface/ICONS/Inv_mace_116:24:24:-18|t[Let me browse your Weapons]"
#define GOSSIP_TEXT_BROWSE_ARMOR_264            "|TInterface/ICONS/inv_chest_cloth_04:24:24:-18|t[Show me T10 Armor]"
#define GOSSIP_TEXT_BROWSE_ACCESSORIES_264      "|TInterface/ICONS/Inv_jewelry_ring_85:24:24:-18|t[Show me off set pieces]"
//245 -------------------------------------
#define GOSSIP_TEXT_BROWSE_WEAPONS_245          "|TInterface/ICONS/Inv_mace_116:24:24:-18|t[Let me browse your Weapons]"
#define GOSSIP_TEXT_BROWSE_ARMOR_245            "|TInterface/ICONS/inv_chest_cloth_04:24:24:-18|t[Show me T9 Armor please]"
#define GOSSIP_TEXT_BROWSE_ACCESSORIES_245      "|TInterface/ICONS/Inv_jewelry_ring_85:24:24:-18|t[Show me off set pieces]"

//npc_vendor database
enum shop_list_id
{
    // T10,5 277_284
    VENDOR_WEAPON_LIST_277_284 =  6666666, 
    VENDOR_ARMOR_LIST_277_284  =  6666667, 
    VENDOR_ACCESSOIRES_LIST_277_284 = 6666668,
  
    // 264
    VENDOR_WEAPON_LIST_264 =  6666669, 
    VENDOR_ARMOR_LIST_264 =  6666670, 
    VENDOR_ACCESSOIRES_LIST_264 = 6666671,

    // 245
    VENDOR_WEAPON_LIST_245 =  6666672, 
    VENDOR_ARMOR_LIST_245 =  6666673, 
    VENDOR_ACCESSOIRES_LIST_245 = 6666674

};


/***********************/
/*NPC_SCRIPTS *********/
/**********************/

class npc_multi_vendor_277_284 : public CreatureScript
{
public:
    npc_multi_vendor_277_284() : CreatureScript("npc_multi_vendor_277_284") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    { 
        if (creature->IsVendor())
            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_WEAPONS_277_284, GOSSIP_ACTION_TRADE, 1);
            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ARMOR_277_284, GOSSIP_ACTION_TRADE, 2);
            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ACCESSORIES_277_284, GOSSIP_ACTION_TRADE, 3);

        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();

        switch (action)
        {
         case 1: // WEAPONS
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                CloseGossipMenuFor(player);
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPON_LIST_277_284);
            }            
             break;
         case 2: // ARMOR
             CloseGossipMenuFor(player);
             if (player->IsInCombat())
             {
                 CloseGossipMenuFor(player);
                 player->GetSession()->SendNotification("You are in combat!");
                 return false;
             }
             else if (player->getClassMask())
             {
               player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ARMOR_LIST_277_284);
             }
             break;
         case 3: // ACCESSORIES
             CloseGossipMenuFor(player);
             if (player->IsInCombat())
             {
                 CloseGossipMenuFor(player);
                 player->GetSession()->SendNotification("You are in combat!");
                 return false;
             }
             else if (player->getClassMask())
             {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ACCESSOIRES_LIST_277_284);
             }
             break;
        }
        return true;
    }
};

class npc_multi_vendor_264 : public CreatureScript
{
public:
    npc_multi_vendor_264() : CreatureScript("npc_multi_vendor_264") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    { 
        if (creature->IsVendor())
            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_WEAPONS_264, GOSSIP_ACTION_TRADE, 1);
            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ARMOR_264, GOSSIP_ACTION_TRADE, 2);
            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ACCESSORIES_264, GOSSIP_ACTION_TRADE, 3);

        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();

        switch (action)
        {
         case 1: // WEAPONS
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                CloseGossipMenuFor(player);
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPON_LIST_264);
            }            
             break;
         case 2: // ARMOR
             CloseGossipMenuFor(player);
             if (player->IsInCombat())
             {
                 CloseGossipMenuFor(player);
                 player->GetSession()->SendNotification("You are in combat!");
                 return false;
             }
             else if (player->getClassMask())
             {
               player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ARMOR_LIST_264);
             }
             break;
         case 3: // ACCESSORIES
             CloseGossipMenuFor(player);
             if (player->IsInCombat())
             {
                 CloseGossipMenuFor(player);
                 player->GetSession()->SendNotification("You are in combat!");
                 return false;
             }
             else if (player->getClassMask())
             {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ACCESSOIRES_LIST_264);
             }
             break;
        }
        return true;
    }
};


class npc_multi_vendor_245 : public CreatureScript
{
public:
    npc_multi_vendor_245() : CreatureScript("npc_multi_vendor_245") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    { 
        if (creature->IsVendor())
            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_WEAPONS_245, GOSSIP_ACTION_TRADE, 1);
            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ARMOR_245, GOSSIP_ACTION_TRADE, 2);
            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_ACCESSORIES_245, GOSSIP_ACTION_TRADE, 3);

        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();

        switch (action)
        {
         case 1: // WEAPONS
            CloseGossipMenuFor(player);
            if (player->IsInCombat())
            {
                CloseGossipMenuFor(player);
                player->GetSession()->SendNotification("You are in combat!");
                return false;
            }
            else if (player->getClassMask())
            {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_WEAPON_LIST_245);
            }            
             break;
         case 2: // ARMORS
             CloseGossipMenuFor(player);
             if (player->IsInCombat())
             {
                 CloseGossipMenuFor(player);
                 player->GetSession()->SendNotification("You are in combat!");
                 return false;
             }
             else if (player->getClassMask())
             {
               player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ARMOR_LIST_245);
             }
             break;
         case 3: // ACCESSORIES
             CloseGossipMenuFor(player);
             if (player->IsInCombat())
             {
                 CloseGossipMenuFor(player);
                 player->GetSession()->SendNotification("You are in combat!");
                 return false;
             }
             else if (player->getClassMask())
             {
                player->GetSession()->SendListInventory(creature->GetGUID(), VENDOR_ACCESSOIRES_LIST_245);
             }
             break;
        }
        return true;
    }
};


void AddMultiVendor_scripts()
{
   new npc_multi_vendor_277_284();
   new npc_multi_vendor_264();
   new npc_multi_vendor_245();
}
