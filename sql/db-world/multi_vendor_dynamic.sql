CREATE TABLE IF NOT EXISTS `mod_multi_vendor_lists` (
  `entry` INT UNSIGNED NOT NULL,
  `action` INT UNSIGNED NOT NULL,
  `sort_order` INT UNSIGNED NOT NULL DEFAULT 0,
  `icon` INT UNSIGNED NOT NULL DEFAULT 1,
  `option_text` VARCHAR(255) NOT NULL,
  `option_text_koKR` VARCHAR(255) NOT NULL DEFAULT '',
  `option_text_frFR` VARCHAR(255) NOT NULL DEFAULT '',
  `option_text_deDE` VARCHAR(255) NOT NULL DEFAULT '',
  `option_text_zhCN` VARCHAR(255) NOT NULL DEFAULT '',
  `option_text_zhTW` VARCHAR(255) NOT NULL DEFAULT '',
  `option_text_esES` VARCHAR(255) NOT NULL DEFAULT '',
  `option_text_esMX` VARCHAR(255) NOT NULL DEFAULT '',
  `option_text_ruRU` VARCHAR(255) NOT NULL DEFAULT '',
  `vendor_entry` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`entry`, `action`),
  KEY `idx_vendor_entry` (`vendor_entry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
