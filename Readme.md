Requirement
===========
In order to run successfully under MingGW64, the macro `_ISOC99_SOURCE` must be defined in `project.yml` for GCC to correctly link to `vsnprintf()` that returns the length of buffer needed to write when it fails due to buffer being too small:
```
:defines:
  # in order to add common defines:
  #  1) remove the trailing [] from the :common: section
  #  2) add entries to the :common: section (e.g. :test: has TEST defined)
  :commmon: &common_defines []
  :test:
    - *common_defines
    - TEST
    - CEXCEPTION_USE_CONFIG_FILE
    # The following macro is to ensure vsnprintf() returns the length of
    # bytes needed to write when it fails due to buffer being too small
    - _ISOC99_SOURCE  
```

Otherwise GCC will use `vsnprintf()` provided by Windows, which will return a -1 if it encountered an error [1]. In this case, my implementation that uses the function will fail, because it expects the correct length required.

Reference
=========
[1] https://sourceforge.net/p/mingw-w64/mailman/message/31241434/


