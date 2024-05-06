@echo off
set PATH=%PATH%;C:\HighTec\toolchains\powerpc\v4.9.3.0\bin;C:\DEV_AREA\raptor\Source\build;C:\DEV_AREA\raptor\Source\GCM-58NN-112\lib
set LDFILES=objs\L9945_raptor_cfg.o objs\Lin_Cfg.o objs\Sent_Cfg.o objs\XCP_App_XCP1.o objs\can_531__0004.o objs\can_532__0004.o objs\can_533__0004.o objs\can_534__0004.o objs\can_535__0004.o objs\data.o objs\platform.o objs\raptor_can_config.o objs\raptor_gen.o objs\raptor_time.o objs\rcm112_stack_check.o objs\rcm112_stack_check_data.o objs\sbc_config.o objs\xcp_protocol.o 
@if exist .\objs rmdir /Q /S .\objs > NUL
@mkdir .\objs > NUL
set PATH=%PATH%;C:\HighTec\toolchains\powerpc\v4.9.3.0\bin
echo ppc-vle-gcc "@compiler.args" -o "./objs/L9945_raptor_cfg.o" L9945_raptor_cfg.c 
ppc-vle-gcc "@compiler.args" -o "./objs/L9945_raptor_cfg.o" L9945_raptor_cfg.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/Lin_Cfg.o" Lin_Cfg.c 
ppc-vle-gcc "@compiler.args" -o "./objs/Lin_Cfg.o" Lin_Cfg.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/Sent_Cfg.o" Sent_Cfg.c 
ppc-vle-gcc "@compiler.args" -o "./objs/Sent_Cfg.o" Sent_Cfg.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/XCP_App_XCP1.o" XCP_App_XCP1.c 
ppc-vle-gcc "@compiler.args" -o "./objs/XCP_App_XCP1.o" XCP_App_XCP1.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/can_531__0004.o" can_531__0004.c 
ppc-vle-gcc "@compiler.args" -o "./objs/can_531__0004.o" can_531__0004.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/can_532__0004.o" can_532__0004.c 
ppc-vle-gcc "@compiler.args" -o "./objs/can_532__0004.o" can_532__0004.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/can_533__0004.o" can_533__0004.c 
ppc-vle-gcc "@compiler.args" -o "./objs/can_533__0004.o" can_533__0004.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/can_534__0004.o" can_534__0004.c 
ppc-vle-gcc "@compiler.args" -o "./objs/can_534__0004.o" can_534__0004.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/can_535__0004.o" can_535__0004.c 
ppc-vle-gcc "@compiler.args" -o "./objs/can_535__0004.o" can_535__0004.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/data.o" data.c 
ppc-vle-gcc "@compiler.args" -o "./objs/data.o" data.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/platform.o" platform.c 
ppc-vle-gcc "@compiler.args" -o "./objs/platform.o" platform.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/raptor_can_config.o" raptor_can_config.c 
ppc-vle-gcc "@compiler.args" -o "./objs/raptor_can_config.o" raptor_can_config.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/raptor_gen.o" raptor_gen.c 
ppc-vle-gcc "@compiler.args" -o "./objs/raptor_gen.o" raptor_gen.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/raptor_time.o" raptor_time.c 
ppc-vle-gcc "@compiler.args" -o "./objs/raptor_time.o" raptor_time.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/rcm112_stack_check.o" rcm112_stack_check.c 
ppc-vle-gcc "@compiler.args" -o "./objs/rcm112_stack_check.o" rcm112_stack_check.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/rcm112_stack_check_data.o" rcm112_stack_check_data.c 
ppc-vle-gcc "@compiler.args" -o "./objs/rcm112_stack_check_data.o" rcm112_stack_check_data.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/sbc_config.o" sbc_config.c 
ppc-vle-gcc "@compiler.args" -o "./objs/sbc_config.o" sbc_config.c 
echo ppc-vle-gcc "@compiler.args" -o "./objs/xcp_protocol.o" xcp_protocol.c 
ppc-vle-gcc "@compiler.args" -o "./objs/xcp_protocol.o" xcp_protocol.c 
if %ERRORLEVEL% NEQ 0 exit /B %ERRORLEVEL%
echo Linking rcm112_stack_check ...
ppc-vle-gcc -o rcm112_stack_check.elf "@hw_linker.args"
if %ERRORLEVEL% NEQ 0 exit /B %ERRORLEVEL%
ppc-vle-objcopy -I elf32-powerpc -O ihex rcm112_stack_check.elf rcm112_stack_check_temp.hex
ppc-vle-objcopy -I elf32-powerpc -O ihex rcm112_stack_check.elf rcm112_stack_check.hex
ppc-vle-nm -a rcm112_stack_check.elf > rcm112_stack_check.sym
echo Copy : rcm112_stack_check.hex 
copy rcm112_stack_check.hex "C:\DEV_AREA\models\MATLAB2023a\rcm112_stack_check\rcm112_stack_check_raptor_rtw\rcm112_stack_check_019.hex" /Y
