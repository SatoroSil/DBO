------------------------------------------------------
-- �Ҿƹ���(�տ���)
-- �ۼ��� : SongJiChul (reep@ntl-inc.com)
------------------------------------------------------

-- TLQ1 User���� RP��ų��� ������ ��Ű�� �Ҿƹ���

Scene(1, "11604")
	--�������� ���� User �� �����ϴٰ� �Ҿƹ����� �״� ���� �������Ѵ�
	--mob�� ��� �ϱ� ���� ���ݹ��� �ʵ��� Param("attack disallow", 1) �����Ѵ�

	Action("char condition")
	--[
		Param("invincible", 1)
		Param("ui disable", 1)
		Param("attack disallow", 1)
	--]
	End()

	Action("say")
	--[
		Param("tblidx", 3005)
	--]
	End()

	Action("char condition")
	--[
		Param("attack disallow", 0)
	--]
	End()

	Action( "sps end" )
	--[
	--]
	End()

End()