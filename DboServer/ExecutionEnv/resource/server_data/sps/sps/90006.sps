-------------------------------------------------
--	Data : 2009-06-25
--	Author : Rudin (byerror@ntl-inc.com)
-------------------------------------------------

-- ��� Path:
-- 90006	��ȣ�� ���� - ���̸��� ���� �ͳ� �Ա�1
-- 90007	��ȣ�� ���� - ���̸��� ���� �ͳ� �Ա�2


-- �����: ��ȣ�� ����
-- ������: ���̸��� ���� �ͳ� �Ա�


Scene(1, "Path 90006")
--[
	Action("sitdown")
	--[
		Param( "sitdown", "true")
	--]
	End()

	Action("wait")
	--[
		Param( "time", 3)
	--]
	End()

	Action("say")
	--[
		Param( "tblidx", 2000)
		-- �̵��� ���Ͻø� �����ϼ���
	--]
	End()

	Action("wait")
	--[
		Param( "time", 9)
	--]
	End()

	Action("say")
	--[
		Param( "tblidx", 2005)
		---- ���̸��� ���� �ͳ� �Ա��� ���� ����մϴ�
	--]
	End()

	Action("sitdown")
	--[
		Param( "sitdown", "false")
	--]
	End()

	Action("wait")
	--[
		Param( "time", 3)
	--]
	End()

	Action("path move")
	--[
		Param( "tblidx", 90006)
		Param( "run mode", 0)
		---- ù��° ��� Path
	--]
	End()

	Action("say")
	--[
		Param( "tblidx", 2001)
		-- �����忡 �����߽��ϴ�
	--]
	End()

	Action("wait")
	--[
		Param( "time", 3)
	--]
	End()

	Action("sitdown")
	--[
		Param( "sitdown", "true")
	--]
	End()

	Action("wait")
	--[
		Param( "time", 3)
	--]
	End()
	
	Action("say")
	--[
		Param( "tblidx", 2000)
		-- (�̵��� ���Ͻø� �����ϼ���)
	--]
	End()

	Action("wait")
	--[
		Param( "time", 9)
	--]
	End()

	Action("say")
	--[
		Param( "tblidx", 2005)
		---- ���̸��� ���� �ͳ� �Ա��� ���� ����մϴ�
	--]
	End()

	Action("sitdown")
	--[
		Param( "sitdown", "false")
	--]
	End()

	Action("wait")
	--[
		Param( "time", 3)
	--]
	End()

	Action("path move")
	--[
		Param( "tblidx", 90007)
		Param( "run mode", 0)
		---- �ι�° ��� Path
	--]
	End()

	Action("say")
	--[
		Param( "tblidx", 2001)
		-- �����忡 �����߽��ϴ�
	--]
	End()

	Action("wait")
	--[
		Param( "time", 3)
	--]
	End()

	Action("sitdown")
	--[
		Param( "sitdown", "true")
	--]
	End()

	Action("wait")
	--[
		Param( "time", 5)
	--]
	End()

	Action( "leave" )
	--[
	--]
	End()

	Action( "sps end" )
	--[
	--]
	End()
--]
End()