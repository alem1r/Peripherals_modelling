CONFIG_ARM_GIC:=$(findstring y,$(CONFIG_ARM_GIC)y)
CONFIG_ARM_GIC_KVM:=$(findstring y,$(CONFIG_ARM_GIC_KVM)$(CONFIG_KVM))
CONFIG_ARM_MPTIMER:=$(findstring y,$(CONFIG_ARM_MPTIMER)y)
CONFIG_ARM_TIMER:=$(findstring y,$(CONFIG_ARM_TIMER)y)
CONFIG_KINETIS:=$(findstring y,$(CONFIG_KINETIS)n)
CONFIG_LPC:=$(findstring y,$(CONFIG_LPC)n)
CONFIG_PCI:=$(findstring y,$(CONFIG_PCI)y)
CONFIG_PTIMER:=$(findstring y,$(CONFIG_PTIMER)y)
CONFIG_SAM:=$(findstring y,$(CONFIG_SAM)n)
CONFIG_STELLARIS:=$(findstring y,$(CONFIG_STELLARIS)y)
CONFIG_STELLARIS_ENET:=$(findstring y,$(CONFIG_STELLARIS_ENET)y)
CONFIG_STELLARIS_INPUT:=$(findstring y,$(CONFIG_STELLARIS_INPUT)y)
CONFIG_STM32:=$(findstring y,$(CONFIG_STM32)y)
CONFIG_TIVA:=$(findstring y,$(CONFIG_TIVA)n)
CONFIG_XMC:=$(findstring y,$(CONFIG_XMC)n)
