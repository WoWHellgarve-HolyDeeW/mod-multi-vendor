SET NAMES utf8mb4;
SET character_set_client = utf8mb4;
SET character_set_connection = utf8mb4;
SET character_set_results = utf8mb4;

DELETE FROM `module_string`
WHERE `module` = 'mod-multi-vendor'
  AND `id` = 1;

INSERT INTO `module_string` (`module`, `id`, `string`) VALUES
('mod-multi-vendor', 1, 'You are in combat!');

DELETE FROM `module_string_locale`
WHERE `module` = 'mod-multi-vendor'
  AND `id` = 1;

INSERT INTO `module_string_locale` (`module`, `id`, `locale`, `string`) VALUES
('mod-multi-vendor', 1, 'koKR', '전투 중입니다!'),
('mod-multi-vendor', 1, 'frFR', 'Vous êtes en combat !'),
('mod-multi-vendor', 1, 'deDE', 'Du bist im Kampf!'),
('mod-multi-vendor', 1, 'zhCN', '你正在战斗中！'),
('mod-multi-vendor', 1, 'zhTW', '你正在戰鬥中！'),
('mod-multi-vendor', 1, 'esES', '¡Estás en combate!'),
('mod-multi-vendor', 1, 'esMX', '¡Estás en combate!'),
('mod-multi-vendor', 1, 'ruRU', 'Вы в бою!');
