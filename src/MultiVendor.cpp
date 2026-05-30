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
#include "Chat.h"
#include "DatabaseEnv.h"
#include "Common.h"

namespace
{
    char constexpr MODULE_NAME[] = "mod-multi-vendor";

    enum ModuleStringIds : uint32
    {
        STRING_ID_IN_COMBAT = 1
    };
}

class npc_multi_vendor_dynamic : public CreatureScript
{
public:
    npc_multi_vendor_dynamic() : CreatureScript("npc_multi_vendor_dynamic") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (!creature->IsVendor())
            return false;

        QueryResult result = WorldDatabase.Query(
            "SELECT `action`, `icon`, `option_text`, "
            "`option_text_koKR`, `option_text_frFR`, `option_text_deDE`, "
            "`option_text_zhCN`, `option_text_zhTW`, `option_text_esES`, `option_text_esMX`, `option_text_ruRU` "
            "FROM `mod_multi_vendor_lists` "
            "WHERE `entry` = {} "
            "ORDER BY `sort_order`, `action`",
            creature->GetEntry());

        if (!result)
            return false;

        do
        {
            Field* fields = result->Fetch();
            uint32 action = fields[0].Get<uint32>();
            uint32 icon = fields[1].Get<uint32>();
            std::string optionText = fields[2].Get<std::string>();
            LocaleConstant locale = player->GetSession()->GetSessionDbcLocale();

            switch (locale)
            {
                case LOCALE_koKR:
                    if (!fields[3].Get<std::string>().empty())
                        optionText = fields[3].Get<std::string>();
                    break;
                case LOCALE_frFR:
                    if (!fields[4].Get<std::string>().empty())
                        optionText = fields[4].Get<std::string>();
                    break;
                case LOCALE_deDE:
                    if (!fields[5].Get<std::string>().empty())
                        optionText = fields[5].Get<std::string>();
                    break;
                case LOCALE_zhCN:
                    if (!fields[6].Get<std::string>().empty())
                        optionText = fields[6].Get<std::string>();
                    break;
                case LOCALE_zhTW:
                    if (!fields[7].Get<std::string>().empty())
                        optionText = fields[7].Get<std::string>();
                    break;
                case LOCALE_esES:
                    if (!fields[8].Get<std::string>().empty())
                        optionText = fields[8].Get<std::string>();
                    break;
                case LOCALE_esMX:
                    if (!fields[9].Get<std::string>().empty())
                        optionText = fields[9].Get<std::string>();
                    break;
                case LOCALE_ruRU:
                    if (!fields[10].Get<std::string>().empty())
                        optionText = fields[10].Get<std::string>();
                    break;
                default:
                    break;
            }

            AddGossipItemFor(player, icon, optionText, GOSSIP_ACTION_TRADE, action);
        } while (result->NextRow());

        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        CloseGossipMenuFor(player);

        if (player->IsInCombat())
        {
            ChatHandler(player->GetSession()).PSendModuleSysMessage(MODULE_NAME, STRING_ID_IN_COMBAT);
            return false;
        }

        QueryResult result = WorldDatabase.Query(
            "SELECT `vendor_entry` "
            "FROM `mod_multi_vendor_lists` "
            "WHERE `entry` = {} AND `action` = {} "
            "LIMIT 1",
            creature->GetEntry(), action);

        if (!result)
            return false;

        uint32 vendorEntry = result->Fetch()[0].Get<uint32>();
        player->GetSession()->SendListInventory(creature->GetGUID(), vendorEntry);
        return true;
    }
};

void AddMultiVendor_scripts()
{
    new npc_multi_vendor_dynamic();
}
