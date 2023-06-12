#include "..\..\pch.h"
int Convert(string t) {
	if (t == "bag_entity")
		return 1;
	if (t == "character_entity")
		return 2;
	if (t == "character_equip_entity")
		return 3;
	if (t == "player_behavior_entity")
		return 4;
	if (t == "player_info_entity")
		return 5;
	if (t == "shop_info_entity")
		return 6;
	if (t == "admin_entity")
		return 7;
}
DbSet::DbSet(mysqlx::Table& t):Table(t)
{
	name_type = Convert(t.getName());
}

DbSet::DbSet(mysqlx::Table& t, int type):Table(t)
{
	name_type = Convert(t.getName());
}

void DbSet::Insert()
{
	if(this->isView())
	{
		cout << "选择表为视图请重新选择" << endl;
		return;
	}
	mysqlx::Result res;
	switch (this->name_type)
	{
	case 1:
		res=this->insert("bag_id", "capacity", "bag_data")
			.values("","","")
			.execute();
		break;
	case 2:
		res=this->insert("player_id","character_id","gender","exp","profession","hp","attack","def", "physical_resist", "equip_name", "equip_id", "bag_id")
			.values("", "", "", "", "", "", "", "", "", "", "", "")
			.execute();
		break;
	case 3:
		res=this->insert("equip_id", "equip_name", "equip_type", "hp", "attack", "def", "phys_resist")
			.values("", "", "", "", "", "","")
			.execute();
		break;
	case 4:
		res=this->insert("player_id", "behavior_type", "behavior_time", "behavior_detail")
			.values("", "", "","")
			.execute();
		break;
	case 5:
		res=this->insert("player_id","character_id","account","nickname","gender","age")
			.values("", "", "", "", "", "")
			.execute();
		break;
	case 6:
		res=this->insert("item_name","item_id","item_description","item_num","item_cost")
			.values("", "", "", "", "")
			.execute();
		break;
	case 7:
		if (true) {
			cout << "权限不足，请申请或者更换登录账户" << endl;
			break;
		}
		res=this->insert("admin_id", "admin_account", "admin_password", "admin_level")
			.values("", "", "","")
			.execute();
			break;
	default:
		cout << "不存在此表，请重新选择" << endl;
		break;
	}
	if (res.getAffectedItemsCount())
	{
		cout << "插入成功！" << endl;
	}
}

void DbSet::Select()
{
	if (this->isView())
	{
		cout << "选择表为视图请重新选择" << endl;
		return;
	}
	mysqlx::RowResult res;
	std::string expr;
	cout << "请输入sql查询条件(sql形式):" << endl;
	cin >> expr;
	switch (this->name_type)
	{
	case 1:
		res = this->select("bag_id", "capacity", "bag_data")
			.where(expr)
			.orderBy("bag_id")
			.execute();
		break;
	case 2:
		res = this->select("player_id", "character_id", "gender", "exp", "profession", "hp", "attack", "physical_resist", "equip_name", "equip_id", "bag_id")
			.where(expr)
			.orderBy("player_id")
			.execute();
		break;
	case 3:
		res = this->select("equip_id", "equip_name", "equip_type", "hp", "attack", "def", "phys_resist")
			.where(expr)
			.orderBy("equip_id")
			.execute();
		break;
	case 4:
		res = this->select("player_id", "behavior_type", "behavior_time", "behavior_detail")
			.where(expr)
			.orderBy("player_id")
			.execute();
		break;
	case 5:
		res = this->select("player_id", "character_id", "account", "nickname", "gender", "age")
			.where(expr)
			.orderBy("player_id")
			.execute();
		break;
	case 6:
		res = this->select("item_name", "item_id", "item_description", "item_num", "item_cost")
			.where(expr)
			.orderBy("item_id")
			.execute();
		break;
	case 7:
		if (true) {
			cout << "权限不足，请申请或者更换登录账户" << endl;
			break;
		}
		res = this->select("admin_id", "admin_account", "admin_password", "admin_level")
			.where(expr)
			.orderBy("admin_id")
			.execute();
		break;
	default:
		cout << "不存在此表，请重新选择" << endl;
		break;
	}
	if (res.getAffectedItemsCount())
	{
		cout << "查询成功！" << endl;
	}

}

void DbSet::Update()
{
	if (this->isView())
	{
		cout << "选择表为视图请重新选择" << endl;
		return;
	}
	mysqlx::Result res;
	std::string expr;
	cout << "请输入更新条件:";
	cin >> expr;
	switch (this->name_type)
	{
	case 1:
		res = this->update()
			.set("capacity",10)
			.set("bag_data","")
			.where(expr)
			.execute();
		break;
	case 2:
		res = this->update()/*insert("player_id", "character_id", "gender", "exp", "profession", "hp", "attack", "physical_resist", "equip_name", "equip_id", "bag_id")*/
			.set("gender",1)
			.set("exp",1)
			.set("profession","")
			.set("hp",1)
			.set("attack",1)
			.set("physical_resist",21.8)
			.where(expr)
			.execute();
		break;
	case 3:
		res = this->update()/*("equip_id", "equip_name", "equip_type", "hp", "attack", "def", "phys_resist")*/
			.set("equip_name","")
			.set("equip_type","")
			.set("hp", 1)
			.set("attack", 1)
			.set("def",12)
			.set("physical_resist", 21.8)
			.where(expr)
			.execute();
		break;
	case 4:
		//("player_id", "behavior_type", "behavior_time", "behavior_detail")
		res = this->update()
			.set("behavior_type",1)
			.set("behavior_time","")
			.set("behavior_detail","")
			.where(expr)
			.execute();
		break;
	case 5:
		//("player_id", "character_id", "account", "nickname", "gender", "age")
		res = this->update()
			.set("account","")
			.set("nickname","")
			.set("gender",1)
			.set("age",1)
			.where(expr)
			.execute();
		break;
	case 6:
		//("item_name", "item_id", "item_description", "item_num", "item_cost")
		res = this->update()
			.set("item_name","")
			.set("item_description","")
			.set("item_num",1)
			.set("item_cost",1)
			.where(expr)
			.execute();
		break;
	case 7:
		if (true) {
			cout << "权限不足，请申请或者更换登录账户" << endl;
			break;
		}
		//("admin_id", "admin_account", "admin_password", "admin_level")
		res = this->update()
			.set("admin_id","")
			.set("admin_account","")
			.set("admin_password","")
			.set("admin_level",1)
			.where(expr)
			.execute();
		break;
	default:
		cout << "不存在此表，请重新选择" << endl;
		break;
	}
	if (res.getAffectedItemsCount())
	{
		cout << "插入成功！" << endl;
	}
}

void DbSet::Remove()
{
	if (this->isView())
	{
		cout << "选择表为视图请重新选择" << endl;
		return;
	}
	mysqlx::Result res;
	std::string expr;
	cout << "请输入删除条件:";
	cin >> expr;
	switch (this->name_type)
	{
	case 1:
		//insert("bag_id", "capacity", "bag_data")
		res = this->remove()
			.where(expr)
			.execute();
		break;
	case 2:
		res = this->remove()
			.where(expr)
			.execute();
		break;
	case 3:
		res = this->remove()
			.where(expr)
			.execute();
		break;
	case 4:
		res = this->remove()
			.where(expr)
			.execute();
		break;
	case 5:
		res = this->remove()
			.where(expr)
			.execute();
		break;
	case 6:
		res = this->remove()
			.where(expr)
			.execute();
		break;
	case 7:
		if (true) {
			cout << "权限不足，请申请或者更换登录账户" << endl;
			break;
		}
		res = this->remove()
			.where(expr)
			.execute();
		break;
	default:
		cout << "不存在此表，请重新选择" << endl;
		break;
	}
	if (res.getAffectedItemsCount())
	{
		cout << "插入成功！" << endl;
	}
}
