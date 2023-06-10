#pragma once
using namespace std;
//MySQL
//namespace:mysqlx
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <mysqlx\xapi.h>
#include <mysqlx\xdevapi.h>
#include <jdbc\mysql_driver.h>
#include <jdbc\mysql_connection.h>
#include <jdbc\cppconn\driver.h>

//std
#include <list>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

//Entity&Interface
#include"Header\Entity\Entity.h"
#include"Header\Entity\Admin.h"
#include"Header\Entity\Bag.h"
#include"Header\Entity\Character.h"
#include"Header\Entity\Equip.h"
#include"Header\Entity\Player_Behaviour.h"
#include"Header\Entity\Player.h"
#include"Header\Entity\Shop.h"


//Util
#include"Header\Util\Menu.h"

//Sql
#include"Header\SqlManager\ORM.h"
#include"Header\SqlManager\DbSet.h"