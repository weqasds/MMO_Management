#pragma once
#define MAPPER(db, name)                                               \
(name == "Admin" ? ORM::DbSet<Admin>(db, name) :                       \
(name == "Bag" ? ORM::DbSet<Bag>(db, name) :                           \
(name == "Character" ? ORM::DbSet<Character>(db, name) :               \
(name == "Equip" ? ORM::DbSet<Equip>(db, name) :                       \
(name == "Player" ? ORM::DbSet<Player>(db, name) :                     \
(name == "Player_Behaviour" ? ORM::DbSet<Player_Behaviour>(db, name) : \
(name == "Shop" ? ORM::DbSet<Shop>(db, name))))))))                    