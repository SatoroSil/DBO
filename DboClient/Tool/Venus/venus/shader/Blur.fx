// -------------------------------------------------------------
// ���콺����
// 
// Copyright (c) 2003 IMAGIRE Takashi. All rights reserved.
// -------------------------------------------------------------

// -------------------------------------------------------------
// ��������
// -------------------------------------------------------------

float	MAP_WIDTH;
float	MAP_HEIGHT;
float	mono_power_height;

float3	RGB2Y;

// -------------------------------------------------------------
// �ؽ�ó
// -------------------------------------------------------------
sampler SrcSamp = sampler_state
{
	MinFilter = LINEAR;
	MagFilter = LINEAR;
	MipFilter = NONE;

	AddressU = Clamp;
	AddressV = Clamp;
};

struct VS_16BOX_OUTPUT
{
    float4 Pos			: POSITION;
	float2 Tex0			: TEXCOORD0;
	float2 Tex1			: TEXCOORD1;
	float2 Tex2			: TEXCOORD2;
	float2 Tex3			: TEXCOORD3;
};

sampler Sampler0;
sampler Sampler1;
float4 PS_LASTDRAW( float2 Tex  : TEXCOORD0) : COLOR
{
//	float4 Color = 0;
//	Color = tex2D( Sampler0, In.Tex0 ) + tex2D( Sampler1, In.Tex1 );
//	return Color;    
	return tex2D( Sampler0, Tex ) + tex2D( Sampler1, Tex );
}

// -------------------------------------------------------------
// -------------------------------------------------------------
// -------------------------------------------------------------
// ���� �κ� ���� ����
// -------------------------------------------------------------
// -------------------------------------------------------------
// -------------------------------------------------------------
float4 PS_MONO_POWER(float2 Tex : TEXCOORD0) : COLOR
{
//	float4 Out = 0;
//	float3 Color = tex2D( SrcSamp, Tex ).xyz; // ������
//	Out = dot(Color, RGB2Y);    // Y�� �״�� ������
//	Out = pow( Out, mono_power_height );
//	return Out;

	float4 Out = 0;
	Out = tex2D( SrcSamp, Tex );
	Out = pow( Out, mono_power_height );	
	Out = dot(Out.xyz, RGB2Y);    // Y�� �״�� ������
	return Out;
}

// -------------------------------------------------------------
// -------------------------------------------------------------
// -------------------------------------------------------------
// 16 Box ���� ���ø�
// -------------------------------------------------------------
// -------------------------------------------------------------
// -------------------------------------------------------------
// ------------------------------------------------------------
// �������̴�
// ------------------------------------------------------------
VS_16BOX_OUTPUT VS_16BOX (
      float4 Pos    : POSITION,          // ������
      float4 Tex    : TEXCOORD0	         // �ؽ�ó��ǥ
){
	VS_16BOX_OUTPUT Out = (VS_16BOX_OUTPUT)0;        // ��µ�����

	// ��ġ��ǥ
	Out.Pos = Pos;

	Out.Tex0 = Tex + float2(-1.0f/MAP_WIDTH, -1.0f/MAP_HEIGHT);
	Out.Tex1 = Tex + float2(+1.0f/MAP_WIDTH, -1.0f/MAP_HEIGHT);
	Out.Tex2 = Tex + float2(-1.0f/MAP_WIDTH, +1.0f/MAP_HEIGHT);
	Out.Tex3 = Tex + float2(+1.0f/MAP_WIDTH, +1.0f/MAP_HEIGHT);

    return Out;
}

// ------------------------------------------------------------
// �ȼ����̴�
// ------------------------------------------------------------
float4 PS_16BOX ( VS_16BOX_OUTPUT In ) : COLOR0
{
	float4 t0 = tex2D(SrcSamp, In.Tex0);
	float4 t1 = tex2D(SrcSamp, In.Tex1);
	float4 t2 = tex2D(SrcSamp, In.Tex2);
	float4 t3 = tex2D(SrcSamp, In.Tex3);

	return (t0+t1+t2+t3) / 4;
}
PixelShader PS = asm
{
    ps_1_1

    def c0, 0.5, 0.5, 0.5, 0.5

    tex t0
    tex t1
    tex t2
    tex t3

    lrp r0, c0, t0, t1 ; r0 = (t0+t1)/2
    lrp r1, c0, t2, t3 ; r1 = (t2+t3)/2
    lrp r0, c0, r0, r1 ; out = (t0+t1+t2+t3)/4
};

// -------------------------------------------------------------
// ��ũ��
// -------------------------------------------------------------
technique TShader
{
    pass P0
    {
        // ���̴�
        VertexShader = NULL;
        PixelShader  = NULL;

		Sampler[0] = (SrcSamp);
    }
	// ���� �κ� ����
    pass P1
    {
        // ���̴�
		VertexShader = NULL;
//		VertexShader = compile vs_1_1 VS_LASTDRAW();
		PixelShader  = compile ps_2_0 PS_LASTDRAW();
    }
    pass P2
    {
        // ���̴�
		VertexShader = NULL;
		PixelShader  = compile ps_2_0 PS_MONO_POWER();
    }
	// 16 Box ���͸�
    pass P3
    {
		// ���̴�
		VertexShader = compile vs_1_1 VS_16BOX();
		PixelShader  = compile ps_2_0 PS_16BOX();

		Sampler[0] = (SrcSamp);
		Sampler[1] = (SrcSamp);
		Sampler[2] = (SrcSamp);
		Sampler[3] = (SrcSamp);
    }
}
