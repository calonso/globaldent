
# ##########################################################
# 
# IntegriSign device's drivers installation script
# 
#          Carlos Alonso Perez
#            13 - 05 - 2009
# 
# ##########################################################

outfile "globaldent-sign-drivers.exe"

installDir $SYSDIR

section

    setOutPath $INSTDIR

    file SignPad.dll
    file ESUtil.dll

sectionEnd
