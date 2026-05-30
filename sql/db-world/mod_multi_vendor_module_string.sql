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
('mod-multi-vendor', 1, 'ruRU', 'Вы в бою!');
