/**
 * DO NOT MODIFY THIS FILE
 *
 * This repository was automatically generated and is NOT to be modified directly.
 * Any repository modifications are meant to be made to the repository extending the base.
 * Any modifications to base repositories are to be made by the generator only
 *
 * @generator ./utils/scripts/generators/repository-generator.pl
 * @docs https://eqemu.gitbook.io/server/in-development/developer-area/repositories
 */

#ifndef EQEMU_BASE_CHARACTER_BUFFS_REPOSITORY_H
#define EQEMU_BASE_CHARACTER_BUFFS_REPOSITORY_H

#include "../../database.h"
#include "../../strings.h"
#include <ctime>


class BaseCharacterBuffsRepository {
public:
	struct CharacterBuffs {
		int32_t     id;
		uint8_t     slot_id;
		uint16_t    spell_id;
		uint8_t     caster_level;
		std::string caster_name;
		uint32_t    ticsremaining;
		uint32_t    counters;
		uint32_t    melee_rune;
		uint32_t    magic_rune;
		uint8_t     persistent;
		int32_t     ExtraDIChance;
		uint8_t     bard_modifier;
		int32_t     bufftype;
	};

	static std::string PrimaryKey()
	{
		return std::string("id");
	}

	static std::vector<std::string> Columns()
	{
		return {
			"id",
			"slot_id",
			"spell_id",
			"caster_level",
			"caster_name",
			"ticsremaining",
			"counters",
			"melee_rune",
			"magic_rune",
			"persistent",
			"ExtraDIChance",
			"bard_modifier",
			"bufftype",
		};
	}

	static std::vector<std::string> SelectColumns()
	{
		return {
			"id",
			"slot_id",
			"spell_id",
			"caster_level",
			"caster_name",
			"ticsremaining",
			"counters",
			"melee_rune",
			"magic_rune",
			"persistent",
			"ExtraDIChance",
			"bard_modifier",
			"bufftype",
		};
	}

	static std::string ColumnsRaw()
	{
		return std::string(Strings::Implode(", ", Columns()));
	}

	static std::string SelectColumnsRaw()
	{
		return std::string(Strings::Implode(", ", SelectColumns()));
	}

	static std::string TableName()
	{
		return std::string("character_buffs");
	}

	static std::string BaseSelect()
	{
		return fmt::format(
			"SELECT {} FROM {}",
			SelectColumnsRaw(),
			TableName()
		);
	}

	static std::string BaseInsert()
	{
		return fmt::format(
			"INSERT INTO {} ({}) ",
			TableName(),
			ColumnsRaw()
		);
	}

	static CharacterBuffs NewEntity()
	{
		CharacterBuffs e{};

		e.id            = 0;
		e.slot_id       = 0;
		e.spell_id      = 0;
		e.caster_level  = 0;
		e.caster_name   = "";
		e.ticsremaining = 0;
		e.counters      = 0;
		e.melee_rune    = 0;
		e.magic_rune    = 0;
		e.persistent    = 0;
		e.ExtraDIChance = 0;
		e.bard_modifier = 10;
		e.bufftype      = 0;

		return e;
	}

	static CharacterBuffs GetCharacterBuffs(
		const std::vector<CharacterBuffs> &character_buffss,
		int character_buffs_id
	)
	{
		for (auto &character_buffs : character_buffss) {
			if (character_buffs.id == character_buffs_id) {
				return character_buffs;
			}
		}

		return NewEntity();
	}

	static CharacterBuffs FindOne(
		Database& db,
		int character_buffs_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE {} = {} LIMIT 1",
				BaseSelect(),
				PrimaryKey(),
				character_buffs_id
			)
		);

		auto row = results.begin();
		if (results.RowCount() == 1) {
			CharacterBuffs e{};

			e.id            = static_cast<int32_t>(atoi(row[0]));
			e.slot_id       = static_cast<uint8_t>(strtoul(row[1], nullptr, 10));
			e.spell_id      = static_cast<uint16_t>(strtoul(row[2], nullptr, 10));
			e.caster_level  = static_cast<uint8_t>(strtoul(row[3], nullptr, 10));
			e.caster_name   = row[4] ? row[4] : "";
			e.ticsremaining = static_cast<uint32_t>(strtoul(row[5], nullptr, 10));
			e.counters      = static_cast<uint32_t>(strtoul(row[6], nullptr, 10));
			e.melee_rune    = static_cast<uint32_t>(strtoul(row[7], nullptr, 10));
			e.magic_rune    = static_cast<uint32_t>(strtoul(row[8], nullptr, 10));
			e.persistent    = static_cast<uint8_t>(strtoul(row[9], nullptr, 10));
			e.ExtraDIChance = static_cast<int32_t>(atoi(row[10]));
			e.bard_modifier = static_cast<uint8_t>(strtoul(row[11], nullptr, 10));
			e.bufftype      = static_cast<int32_t>(atoi(row[12]));

			return e;
		}

		return NewEntity();
	}

	static int DeleteOne(
		Database& db,
		int character_buffs_id
	)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {} = {}",
				TableName(),
				PrimaryKey(),
				character_buffs_id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int UpdateOne(
		Database& db,
		const CharacterBuffs &e
	)
	{
		std::vector<std::string> v;

		auto columns = Columns();

		v.push_back(columns[0] + " = " + std::to_string(e.id));
		v.push_back(columns[1] + " = " + std::to_string(e.slot_id));
		v.push_back(columns[2] + " = " + std::to_string(e.spell_id));
		v.push_back(columns[3] + " = " + std::to_string(e.caster_level));
		v.push_back(columns[4] + " = '" + Strings::Escape(e.caster_name) + "'");
		v.push_back(columns[5] + " = " + std::to_string(e.ticsremaining));
		v.push_back(columns[6] + " = " + std::to_string(e.counters));
		v.push_back(columns[7] + " = " + std::to_string(e.melee_rune));
		v.push_back(columns[8] + " = " + std::to_string(e.magic_rune));
		v.push_back(columns[9] + " = " + std::to_string(e.persistent));
		v.push_back(columns[10] + " = " + std::to_string(e.ExtraDIChance));
		v.push_back(columns[11] + " = " + std::to_string(e.bard_modifier));
		v.push_back(columns[12] + " = " + std::to_string(e.bufftype));

		auto results = db.QueryDatabase(
			fmt::format(
				"UPDATE {} SET {} WHERE {} = {}",
				TableName(),
				Strings::Implode(", ", v),
				PrimaryKey(),
				e.id
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static CharacterBuffs InsertOne(
		Database& db,
		CharacterBuffs e
	)
	{
		std::vector<std::string> v;

		v.push_back(std::to_string(e.id));
		v.push_back(std::to_string(e.slot_id));
		v.push_back(std::to_string(e.spell_id));
		v.push_back(std::to_string(e.caster_level));
		v.push_back("'" + Strings::Escape(e.caster_name) + "'");
		v.push_back(std::to_string(e.ticsremaining));
		v.push_back(std::to_string(e.counters));
		v.push_back(std::to_string(e.melee_rune));
		v.push_back(std::to_string(e.magic_rune));
		v.push_back(std::to_string(e.persistent));
		v.push_back(std::to_string(e.ExtraDIChance));
		v.push_back(std::to_string(e.bard_modifier));
		v.push_back(std::to_string(e.bufftype));

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES ({})",
				BaseInsert(),
				Strings::Implode(",", v)
			)
		);

		if (results.Success()) {
			e.id = results.LastInsertedID();
			return e;
		}

		e = NewEntity();

		return e;
	}

	static int InsertMany(
		Database& db,
		const std::vector<CharacterBuffs> &entries
	)
	{
		std::vector<std::string> insert_chunks;

		for (auto &e: entries) {
			std::vector<std::string> v;

			v.push_back(std::to_string(e.id));
			v.push_back(std::to_string(e.slot_id));
			v.push_back(std::to_string(e.spell_id));
			v.push_back(std::to_string(e.caster_level));
			v.push_back("'" + Strings::Escape(e.caster_name) + "'");
			v.push_back(std::to_string(e.ticsremaining));
			v.push_back(std::to_string(e.counters));
			v.push_back(std::to_string(e.melee_rune));
			v.push_back(std::to_string(e.magic_rune));
			v.push_back(std::to_string(e.persistent));
			v.push_back(std::to_string(e.ExtraDIChance));
			v.push_back(std::to_string(e.bard_modifier));
			v.push_back(std::to_string(e.bufftype));

			insert_chunks.push_back("(" + Strings::Implode(",", v) + ")");
		}

		std::vector<std::string> v;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} VALUES {}",
				BaseInsert(),
				Strings::Implode(",", insert_chunks)
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static std::vector<CharacterBuffs> All(Database& db)
	{
		std::vector<CharacterBuffs> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{}",
				BaseSelect()
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			CharacterBuffs e{};

			e.id            = static_cast<int32_t>(atoi(row[0]));
			e.slot_id       = static_cast<uint8_t>(strtoul(row[1], nullptr, 10));
			e.spell_id      = static_cast<uint16_t>(strtoul(row[2], nullptr, 10));
			e.caster_level  = static_cast<uint8_t>(strtoul(row[3], nullptr, 10));
			e.caster_name   = row[4] ? row[4] : "";
			e.ticsremaining = static_cast<uint32_t>(strtoul(row[5], nullptr, 10));
			e.counters      = static_cast<uint32_t>(strtoul(row[6], nullptr, 10));
			e.melee_rune    = static_cast<uint32_t>(strtoul(row[7], nullptr, 10));
			e.magic_rune    = static_cast<uint32_t>(strtoul(row[8], nullptr, 10));
			e.persistent    = static_cast<uint8_t>(strtoul(row[9], nullptr, 10));
			e.ExtraDIChance = static_cast<int32_t>(atoi(row[10]));
			e.bard_modifier = static_cast<uint8_t>(strtoul(row[11], nullptr, 10));
			e.bufftype      = static_cast<int32_t>(atoi(row[12]));

			all_entries.push_back(e);
		}

		return all_entries;
	}

	static std::vector<CharacterBuffs> GetWhere(Database& db, const std::string &where_filter)
	{
		std::vector<CharacterBuffs> all_entries;

		auto results = db.QueryDatabase(
			fmt::format(
				"{} WHERE {}",
				BaseSelect(),
				where_filter
			)
		);

		all_entries.reserve(results.RowCount());

		for (auto row = results.begin(); row != results.end(); ++row) {
			CharacterBuffs e{};

			e.id            = static_cast<int32_t>(atoi(row[0]));
			e.slot_id       = static_cast<uint8_t>(strtoul(row[1], nullptr, 10));
			e.spell_id      = static_cast<uint16_t>(strtoul(row[2], nullptr, 10));
			e.caster_level  = static_cast<uint8_t>(strtoul(row[3], nullptr, 10));
			e.caster_name   = row[4] ? row[4] : "";
			e.ticsremaining = static_cast<uint32_t>(strtoul(row[5], nullptr, 10));
			e.counters      = static_cast<uint32_t>(strtoul(row[6], nullptr, 10));
			e.melee_rune    = static_cast<uint32_t>(strtoul(row[7], nullptr, 10));
			e.magic_rune    = static_cast<uint32_t>(strtoul(row[8], nullptr, 10));
			e.persistent    = static_cast<uint8_t>(strtoul(row[9], nullptr, 10));
			e.ExtraDIChance = static_cast<int32_t>(atoi(row[10]));
			e.bard_modifier = static_cast<uint8_t>(strtoul(row[11], nullptr, 10));
			e.bufftype      = static_cast<int32_t>(atoi(row[12]));

			all_entries.push_back(e);
		}

		return all_entries;
	}

	static int DeleteWhere(Database& db, const std::string &where_filter)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"DELETE FROM {} WHERE {}",
				TableName(),
				where_filter
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int Truncate(Database& db)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"TRUNCATE TABLE {}",
				TableName()
			)
		);

		return (results.Success() ? results.RowsAffected() : 0);
	}

	static int64 GetMaxId(Database& db)
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"SELECT COALESCE(MAX({}), 0) FROM {}",
				PrimaryKey(),
				TableName()
			)
		);

		return (results.Success() && results.begin()[0] ? strtoll(results.begin()[0], nullptr, 10) : 0);
	}

	static int64 Count(Database& db, const std::string &where_filter = "")
	{
		auto results = db.QueryDatabase(
			fmt::format(
				"SELECT COUNT(*) FROM {} {}",
				TableName(),
				(where_filter.empty() ? "" : "WHERE " + where_filter)
			)
		);

		return (results.Success() && results.begin()[0] ? strtoll(results.begin()[0], nullptr, 10) : 0);
	}

};

#endif //EQEMU_BASE_CHARACTER_BUFFS_REPOSITORY_H
