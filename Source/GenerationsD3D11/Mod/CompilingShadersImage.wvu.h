#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Buffer Definitions: 
//
// cbuffer cbGlobals
// {
//
//   float4 g_ViewportSize;             // Offset: 2880 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- -------------- ------
// cbGlobals                         cbuffer      NA          NA            cb0      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_VertexID              0   x           0   VERTID    uint   x   
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Position              0   xyzw        0      POS   float   xyzw
// TEXCOORD                 0   xy          1     NONE   float   xy  
//
vs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[181], immediateIndexed
dcl_input_sgv v0.x, vertex_id
dcl_output_siv o0.xyzw, position
dcl_output o1.xy
dcl_temps 2
bfi r0.x, l(1), l(1), v0.x, l(0)
and r0.w, v0.x, l(2)
utof r0.yz, r0.xxwx
mul r0.yw, r0.yyyz, l(0.000000, 0.500000, 0.000000, 0.500000)
mul r1.x, cb0[180].z, cb0[180].y
mul r0.x, r0.y, r1.x
mov o1.xy, r0.ywyy
mul r1.x, r1.x, l(0.004167)
mov r1.y, l(0.968056)
mad r0.xy, r0.xzxx, l(0.218056, 0.015278, 0.000000, 0.000000), r1.xyxx
mad o0.xy, r0.xyxx, l(2.000000, -2.000000, 0.000000, 0.000000), l(-1.000000, 1.000000, 0.000000, 0.000000)
mov o0.zw, l(0,0,0,1.000000)
ret 
// Approximately 13 instruction slots used
#endif

const BYTE g_compiling_shaders_image_vs_main[] =
{
     68,  88,  66,  67, 177,  70, 
    185, 112,  85, 146, 194, 125, 
     93, 243,  71,  58,   1, 171, 
    247, 125,   1,   0,   0,   0, 
     96,   4,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     72,   1,   0,   0, 124,   1, 
      0,   0, 212,   1,   0,   0, 
    196,   3,   0,   0,  82,  68, 
     69,  70,  12,   1,   0,   0, 
      1,   0,   0,   0, 104,   0, 
      0,   0,   1,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
    254, 255,   0,   1,   0,   0, 
    228,   0,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
     92,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  99,  98,  71, 108, 
    111,  98,  97, 108, 115,   0, 
    171, 171,  92,   0,   0,   0, 
      1,   0,   0,   0, 128,   0, 
      0,   0,  80,  11,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 168,   0,   0,   0, 
     64,  11,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    192,   0,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    103,  95,  86, 105, 101, 119, 
    112, 111, 114, 116,  83, 105, 
    122, 101,   0, 102, 108, 111, 
     97, 116,  52,   0, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 183,   0,   0,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  49, 
     48,  46,  49,   0,  73,  83, 
     71,  78,  44,   0,   0,   0, 
      1,   0,   0,   0,   8,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   1,   1, 
      0,   0,  83,  86,  95,  86, 
    101, 114, 116, 101, 120,  73, 
     68,   0,  79,  83,  71,  78, 
     80,   0,   0,   0,   2,   0, 
      0,   0,   8,   0,   0,   0, 
     56,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     68,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   3,  12,   0,   0, 
     83,  86,  95,  80, 111, 115, 
    105, 116, 105, 111, 110,   0, 
     84,  69,  88,  67,  79,  79, 
     82,  68,   0, 171, 171, 171, 
     83,  72,  69,  88, 232,   1, 
      0,   0,  80,   0,   1,   0, 
    122,   0,   0,   0, 106,   8, 
      0,   1,  89,   0,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0, 181,   0,   0,   0, 
     96,   0,   0,   4,  18,  16, 
     16,   0,   0,   0,   0,   0, 
      6,   0,   0,   0, 103,   0, 
      0,   4, 242,  32,  16,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
     50,  32,  16,   0,   1,   0, 
      0,   0, 104,   0,   0,   2, 
      2,   0,   0,   0, 140,   0, 
      0,  11,  18,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,  10,  16,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   7, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     10,  16,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      2,   0,   0,   0,  86,   0, 
      0,   5,  98,   0,  16,   0, 
      0,   0,   0,   0,   6,   3, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,  10, 162,   0, 
     16,   0,   0,   0,   0,   0, 
     86,   9,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,  63,   0,   0,   0,   0, 
      0,   0,   0,  63,  56,   0, 
      0,   9,  18,   0,  16,   0, 
      1,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
    180,   0,   0,   0,  26, 128, 
     32,   0,   0,   0,   0,   0, 
    180,   0,   0,   0,  56,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  54,   0,   0,   5, 
     50,  32,  16,   0,   1,   0, 
      0,   0, 214,   5,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0, 137, 136, 
    136,  59,  54,   0,   0,   5, 
     34,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
    126, 210, 119,  63,  50,   0, 
      0,  12,  50,   0,  16,   0, 
      0,   0,   0,   0, 134,   0, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0, 245,  73, 
     95,  62, 165,  79, 122,  60, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  15,  50,  32,  16,   0, 
      0,   0,   0,   0,  70,   0, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,  64,   0,   0,   0, 192, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128, 191,   0,   0, 
    128,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   8, 194,  32,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 128,  63, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 148,   0,   0,   0, 
     13,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   6,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0
};
