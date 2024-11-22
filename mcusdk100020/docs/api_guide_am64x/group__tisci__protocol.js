var group__tisci__protocol =
[
    [ "Sciclient_RomFirmwareLoadHdr_t", "structtisci__header.html", [
      [ "type", "structtisci__header.html#aa0c5c9a40eb6a621cf5e72624898ac8f", null ],
      [ "host", "structtisci__header.html#ae0a9757bc7d4dfb23ac854e09a16537f", null ],
      [ "seq", "structtisci__header.html#a5bc66661addd441f809feeffaf9c6ce0", null ],
      [ "flags", "structtisci__header.html#aa5814f09f6cf46b982aed8d56354ad91", null ]
    ] ],
    [ "tisci_sec_header", "structtisci__sec__header.html", [
      [ "integ_check", "structtisci__sec__header.html#a40b7e0a65a61787e00abda1fd3568ea9", null ],
      [ "rsvd", "structtisci__sec__header.html#ae0467ef9407551dfa7b48b8e5f4738bd", null ]
    ] ],
    [ "TISCI_MSG_FLAG_RESERVED0", "group__tisci__protocol.html#ga65b0fd4fe0130f755e8e247cd29a9d56", null ],
    [ "TISCI_MSG_FLAG_AOP", "group__tisci__protocol.html#ga1922bd4a21b63c38721323bc1d70d664", null ],
    [ "TISCI_MSG_FLAG_SEC", "group__tisci__protocol.html#ga2a186df2a75d56e9dbe19bc8b5785805", null ],
    [ "TISCI_MSG_FLAG_ACK", "group__tisci__protocol.html#ga219db5767c05ba48646d24f06623ed09", null ],
    [ "TISCI_MSG_VERSION", "group__tisci__protocol.html#ga015c9f5c1a4a786e311079c4f1857fba", null ],
    [ "TISCI_MSG_BOOT_NOTIFICATION", "group__tisci__protocol.html#ga09c2fe6b3c7a6ccb73dd1409d34d9698", null ],
    [ "TISCI_MSG_BOARD_CONFIG", "group__tisci__protocol.html#ga4b65617024f2e368737c758ac05853e4", null ],
    [ "TISCI_MSG_BOARD_CONFIG_RM", "group__tisci__protocol.html#ga0e118ff7afcc8e87e24aa09f8c1325fc", null ],
    [ "TISCI_MSG_BOARD_CONFIG_SECURITY", "group__tisci__protocol.html#ga777aa01131c787dfffc809a576e609d6", null ],
    [ "TISCI_MSG_BOARD_CONFIG_PM", "group__tisci__protocol.html#ga3d272429fb89388a12e7ad3e442a0f96", null ],
    [ "TISCI_MSG_ENABLE_WDT", "group__tisci__protocol.html#ga16a41e47bd6f7f47be68e0bdb3d2d7f9", null ],
    [ "TISCI_MSG_WAKE_RESET", "group__tisci__protocol.html#ga9c92db7723fadd751d2fa96f24b17cdf", null ],
    [ "TISCI_MSG_WAKE_REASON", "group__tisci__protocol.html#ga010cc3f2cc5da0afffcf96839c09d917", null ],
    [ "TISCI_MSG_GOODBYE", "group__tisci__protocol.html#gab3e65d62af87c7e300b8b62981526e40", null ],
    [ "TISCI_MSG_SYS_RESET", "group__tisci__protocol.html#ga8d7e0b0356b304557355a6a2255662ff", null ],
    [ "TISCI_MSG_QUERY_MSMC", "group__tisci__protocol.html#gad7538e30cd3bad69956781f4aaa863b5", null ],
    [ "TISCI_MSG_GET_TRACE_CONFIG", "group__tisci__protocol.html#ga2adb38c1ad59bc2af992bc88c7c16c12", null ],
    [ "TISCI_MSG_QUERY_FW_CAPS", "group__tisci__protocol.html#ga42171e1d5fe902c2e8f50243476cf5f5", null ],
    [ "TISCI_MSG_SET_CLOCK", "group__tisci__protocol.html#ga4c30efc1c9bd20f12a32e4e9d2c5298a", null ],
    [ "TISCI_MSG_GET_CLOCK", "group__tisci__protocol.html#ga2d3a70cd6ef8e298b3257d2e595de197", null ],
    [ "TISCI_MSG_SET_CLOCK_PARENT", "group__tisci__protocol.html#ga83745695057d6228dbef11c8a094512a", null ],
    [ "TISCI_MSG_GET_CLOCK_PARENT", "group__tisci__protocol.html#ga88390f60596bd4162273c38723bfc1b0", null ],
    [ "TISCI_MSG_GET_NUM_CLOCK_PARENTS", "group__tisci__protocol.html#gae312773fd92cfd5e79c92bb86d25850f", null ],
    [ "TISCI_MSG_SET_FREQ", "group__tisci__protocol.html#ga135e53f9a570a03dc1ea6ca6f9124489", null ],
    [ "TISCI_MSG_QUERY_FREQ", "group__tisci__protocol.html#gae86b3ed61549ca17a3d55d9ae95887ba", null ],
    [ "TISCI_MSG_GET_FREQ", "group__tisci__protocol.html#ga252223e55b10fc691b4e58c9bfb4ae42", null ],
    [ "TISCI_MSG_SET_DEVICE", "group__tisci__protocol.html#ga67a45dd9893de5beccd5a7063ee5b15a", null ],
    [ "TISCI_MSG_GET_DEVICE", "group__tisci__protocol.html#ga0b57afe275646e30aa9620098969e983", null ],
    [ "TISCI_MSG_SET_DEVICE_RESETS", "group__tisci__protocol.html#ga93656c289ae590b3958690d3c30b9a25", null ],
    [ "TISCI_MSG_DEVICE_DROP_POWERUP_REF", "group__tisci__protocol.html#ga0ad7e5f77d7d66b72c476d92de2c0036", null ],
    [ "TISCI_MSG_PREPARE_SLEEP", "group__tisci__protocol.html#ga2646a77c4f0e64157698bc9bff7689ff", null ],
    [ "TISCI_MSG_ENTER_SLEEP", "group__tisci__protocol.html#ga8913e5f69b06018d6de216eba9ec2ea9", null ],
    [ "TISCI_MSG_SYNC_RESUME", "group__tisci__protocol.html#gab2aad251139d8e9290bad338adf8a5fc", null ],
    [ "TISCI_MSG_CONTINUE_RESUME", "group__tisci__protocol.html#ga17f2e2b3dd33ca70f4c539864cab57d9", null ],
    [ "TISCI_MSG_CORE_RESUME", "group__tisci__protocol.html#gaa37e4127fb719a070a2bb3f0dd3ed965", null ],
    [ "TISCI_MSG_ABORT_ENTER_SLEEP", "group__tisci__protocol.html#gaaf61deadac31fc0be9bcef76e7d9b28c", null ],
    [ "TISCI_MSG_LPM_WAKE_REASON", "group__tisci__protocol.html#ga36e1b06165d344e77b1bb16cbe641418", null ],
    [ "TISCI_MSG_SET_IO_ISOLATION", "group__tisci__protocol.html#ga5c73e01d1fa4f96d02c4473f58d02793", null ],
    [ "TISCI_MSG_MIN_CONTEXT_RESTORE", "group__tisci__protocol.html#gad8cd6dd76677c0a817fa5a14507a94fe", null ],
    [ "TISCI_MSG_LPM_SET_DEVICE_CONSTRAINT", "group__tisci__protocol.html#ga1e7a6f2a17ecb92426da231606cc5ece", null ],
    [ "TISCI_MSG_LPM_SET_LATENCY_CONSTRAINT", "group__tisci__protocol.html#ga6f31c851e85c3f47ed53cb20d6f4066a", null ],
    [ "TISCI_MSG_LPM_GET_DEVICE_CONSTRAINT", "group__tisci__protocol.html#ga464441ff8dc3e11e1140cf817794d537", null ],
    [ "TISCI_MSG_LPM_GET_LATENCY_CONSTRAINT", "group__tisci__protocol.html#ga8583b7dcb465c5e4d2ea87e6fb1434f0", null ],
    [ "TISCI_MSG_LPM_GET_NEXT_SYS_MODE", "group__tisci__protocol.html#gac7015539da992e2e92c4c1e733240407", null ],
    [ "TISCI_MSG_LPM_GET_NEXT_HOST_STATE", "group__tisci__protocol.html#gad0603f35205e852b7dbc205b102782d9", null ],
    [ "TISCI_MSG_FIRMWARE_LOAD", "group__tisci__protocol.html#gaa39ebe97c743eeedadf1e627fb8e3927", null ],
    [ "MSG_FIRMWARE_LOAD_RESULT", "group__tisci__protocol.html#gaa7309d0a185f843b905aba550ffc9fee", null ],
    [ "TISCI_MSG_SET_FWL_REGION", "group__tisci__protocol.html#ga8ea3304b5c28e10dba21f495c1015d9e", null ],
    [ "TISCI_MSG_GET_FWL_REGION", "group__tisci__protocol.html#gaa328abaf23696f951fa0ebf3e9ad0d58", null ],
    [ "TISCI_MSG_CHANGE_FWL_OWNER", "group__tisci__protocol.html#ga1f157210c8cb5632892edd4a7977d7d4", null ],
    [ "TISCI_MSG_SA2UL_SET_DKEK", "group__tisci__protocol.html#ga92a66fb517c17a760ec2b1371d998a67", null ],
    [ "TISCI_MSG_SA2UL_RELEASE_DKEK", "group__tisci__protocol.html#gab10fee86950e0f67fca7f8733bfdd730", null ],
    [ "TISCI_MSG_KEYSTORE_IMPORT_SKEY", "group__tisci__protocol.html#ga7b58465b5a70d92c356f9b380e3f0533", null ],
    [ "TISCI_MSG_KEYSTORE_ERASE_SKEY", "group__tisci__protocol.html#ga03be11abb1e13a7a1ca4e289fa98dab9", null ],
    [ "TISCI_MSG_SEC_RESERVED_9007", "group__tisci__protocol.html#gac93e7798600988bbabb037652c7c07b9", null ],
    [ "TISCI_MSG_SEC_RESERVED_9008", "group__tisci__protocol.html#ga54ba6ea294fa27108460030ceb040c8b", null ],
    [ "TISCI_MSG_SET_ISC_REGION", "group__tisci__protocol.html#ga9cbeb154f652039ebf391bd08abd158a", null ],
    [ "TISCI_MSG_GET_ISC_REGION", "group__tisci__protocol.html#ga0fe44f70f577bb670d04da353ed2f598", null ],
    [ "TISCI_MSG_FWL_EXCP_NOTIFICATION", "group__tisci__protocol.html#ga24e723be0b9b38948fc58e8964f0d46e", null ],
    [ "TISCI_MSG_OPEN_DEBUG_FWLS", "group__tisci__protocol.html#gabb94357ee657bb02178dea4406d181f8", null ],
    [ "TISCI_MSG_KEYSTORE_WRITE", "group__tisci__protocol.html#ga3c866935ee894aa8764ca972ffcfa03e", null ],
    [ "TISCI_MSG_KEYSTORE_EXPORT_ALL", "group__tisci__protocol.html#ga4e872ca29d2004da5d58e816c35925b2", null ],
    [ "TISCI_MSG_KEYSTORE_IMPORT_ALL", "group__tisci__protocol.html#ga73ee5a1f23c173a3814bf9061deca48d", null ],
    [ "TISCI_MSG_SEC_RESERVED_9010", "group__tisci__protocol.html#ga20c63008b570265d901c8dc9cfe26808", null ],
    [ "TISCI_MSG_SEC_RESERVED_9011", "group__tisci__protocol.html#ga1ba804accd49961a5d68442feea2f37c", null ],
    [ "TISCI_MSG_SEC_RESERVED_9012", "group__tisci__protocol.html#ga9cba3c29f07998c45f7fb6aef2733caa", null ],
    [ "TISCI_MSG_SEC_RESERVED_9013", "group__tisci__protocol.html#ga5bd1527581c57b074a7c6b7a0e187b2e", null ],
    [ "TISCI_MSG_SEC_RESERVED_9014", "group__tisci__protocol.html#ga875a722047b815444257915c8216d30b", null ],
    [ "TISCI_MSG_SEC_RESERVED_9015", "group__tisci__protocol.html#ga1e98fe447718824d17ef1718534c7242", null ],
    [ "TISCI_MSG_SEC_RESERVED_9016", "group__tisci__protocol.html#ga8bf882a7e0de9a70d94ba957f2608c1b", null ],
    [ "TISCI_MSG_SA2UL_AUTH_RES_ACQUIRE", "group__tisci__protocol.html#ga5b82b92269c5086885b489beef479671", null ],
    [ "TISCI_MSG_SA2UL_AUTH_RES_RELEASE", "group__tisci__protocol.html#gaff60bff981368e0763c888d114357ce1", null ],
    [ "TISCI_MSG_SEC_RESERVED_9020", "group__tisci__protocol.html#ga79f5a858b9e1e9fe8b7c91195d21de64", null ],
    [ "TISCI_MSG_GET_SOC_UID", "group__tisci__protocol.html#ga218f09e59f4584bb29f2262fc749e92e", null ],
    [ "TISCI_MSG_READ_OTP_MMR", "group__tisci__protocol.html#ga34106bd4356a72f0c1e0e3cdd822ef0a", null ],
    [ "TISCI_MSG_WRITE_OTP_ROW", "group__tisci__protocol.html#ga2641332f95060d8bf596f1ca6edb2b86", null ],
    [ "TISCI_MSG_LOCK_OTP_ROW", "group__tisci__protocol.html#ga54f98baba1a23e5cc0284f4a5c17e537", null ],
    [ "TISCI_MSG_SOFT_LOCK_OTP_WRITE_GLOBAL", "group__tisci__protocol.html#gae12a14747488a190e8240b6882ef9b8e", null ],
    [ "TISCI_MSG_GET_OTP_ROW_LOCK_STATUS", "group__tisci__protocol.html#gaeccfaca5615198dde70dcf085b4a6772", null ],
    [ "TISCI_MSG_RSVD_OTP_1", "group__tisci__protocol.html#ga1cf00472c78a57966d5da0da4abd7e33", null ],
    [ "TISCI_MSG_RSVD_OTP_2", "group__tisci__protocol.html#gae92df9913d4e4222168a99ff51aba3b1", null ],
    [ "TISCI_MSG_SA2UL_GET_DKEK", "group__tisci__protocol.html#gadc4a062b844f61eab0cbe6c56cb3fc85", null ],
    [ "TISCI_MSG_ALLOW_FWL_CTRL_READ", "group__tisci__protocol.html#gae430ca6cdab372a82fed35c90a59476f", null ],
    [ "TISCI_MSG_FORBID_FWL_CTRL_READ", "group__tisci__protocol.html#gaff51b3f47a18e5adab9f448edf4068c8", null ],
    [ "TISCI_MSG_SEC_HANDOVER", "group__tisci__protocol.html#ga5bb7e03b209a9720d857ea90f6090023", null ],
    [ "TISCI_MSG_KEY_WRITER", "group__tisci__protocol.html#ga991943d6ce5d85e205b4d78268cc468f", null ],
    [ "TISCI_MSG_WRITE_SWREV", "group__tisci__protocol.html#ga7c82f25f1862301f112265d26d26aeef", null ],
    [ "TISCI_MSG_READ_SWREV", "group__tisci__protocol.html#gaa73e475871f5a217d53ce58b7f41d619", null ],
    [ "TISCI_MSG_READ_KEYCNT_KEYREV", "group__tisci__protocol.html#gac60a418d74cfe901a1248834699fd005", null ],
    [ "TISCI_MSG_WRITE_KEYREV", "group__tisci__protocol.html#ga3bca89daf9a94d0b10189d424e675fee", null ],
    [ "TISCI_MSG_SA2UL_GET_DSMEK", "group__tisci__protocol.html#ga453f4c529da6355736375ff4ac112143", null ],
    [ "TISCI_MSG_SA2UL_SET_DSMEK", "group__tisci__protocol.html#ga054edd4a2f297475265231db3be436a3", null ],
    [ "TISCI_MSG_SA2UL_RELEASE_DSMEK", "group__tisci__protocol.html#ga260bc059eca523640d20ee8f6ef4bf64", null ],
    [ "TISCI_MSG_KEYRING_IMPORT", "group__tisci__protocol.html#ga7f10b9eda4ab9206d044075a2875dc8d", null ],
    [ "TISCI_MSG_SA2UL_SET_DKEK_CONST", "group__tisci__protocol.html#ga6aa3e1e43d2fbf3c51fb87f01d933c98", null ],
    [ "TISCI_MSG_SA2UL_GET_DKEK_CONST", "group__tisci__protocol.html#ga9f388942573f61ba3d3590b3097964b0", null ],
    [ "TISCI_MSG_SA2UL_AES_ENCRYPT", "group__tisci__protocol.html#gad764d55dfe61ffa05c8c17d709021a89", null ],
    [ "TISCI_MSG_SA2UL_AES_DECRYPT", "group__tisci__protocol.html#gac29424980c700e3ef9788b4c7912b0cc", null ],
    [ "TISCI_MSG_PROC_REQUEST", "group__tisci__protocol.html#gae7e87e9e33cf094d076789307b5ce5fc", null ],
    [ "TISCI_MSG_PROC_RELEASE", "group__tisci__protocol.html#ga1609277ed75462d4dba24089ffb2116f", null ],
    [ "TISCI_MSG_PROC_HANDOVER", "group__tisci__protocol.html#gaf2eaad424bab459e969a06570fa19d24", null ],
    [ "TISCI_MSG_PROC_SET_CONFIG", "group__tisci__protocol.html#gaca6c379f0327d5abdc9b2e62e4279d73", null ],
    [ "TISCI_MSG_PROC_SET_CONTROL", "group__tisci__protocol.html#gac95b7a9a4688b82b3f84bb0b71bdc4e0", null ],
    [ "TISCI_MSG_PROC_GET_STATUS", "group__tisci__protocol.html#ga3472b919c613bd2d2538401f03a299f0", null ],
    [ "TISCI_MSG_PROC_WAIT_STATUS", "group__tisci__protocol.html#ga2d98e55ba3abcf4fe527ab218a7f333f", null ],
    [ "TISCI_MSG_PROC_AUTH_BOOT", "group__tisci__protocol.html#gad55b47e9846289fe259e71809173ae98", null ],
    [ "TISCI_MSG_RM_GET_RESOURCE_RANGE", "group__tisci__protocol.html#gac307c50324680efe935e8ec2a7889da2", null ],
    [ "TISCI_MSG_RM_IRQ_SET", "group__tisci__protocol.html#ga75f64bde1fa022730a6c857684020c38", null ],
    [ "TISCI_MSG_RM_IRQ_RELEASE", "group__tisci__protocol.html#gab92a46ad69d1347b3bcf2376b12d1d54", null ],
    [ "TISCI_MSG_RM_RESERVED_1100", "group__tisci__protocol.html#ga4bfdfda42967add5aeae7b3acd8ac950", null ],
    [ "TISCI_MSG_RM_RESERVED_1101", "group__tisci__protocol.html#ga4342484f4530c0d5f8920ad9d57e4cac", null ],
    [ "TISCI_MSG_RM_RESERVED_1102", "group__tisci__protocol.html#ga2593f6bb455962a955fa189fe42df774", null ],
    [ "TISCI_MSG_RM_RESERVED_1103", "group__tisci__protocol.html#gaff32226b82f4b14cae682897ae4ea84c", null ],
    [ "TISCI_MSG_RM_RING_CFG", "group__tisci__protocol.html#gadc0bbe61ae14b43e30a55a8d11eaf510", null ],
    [ "TISCI_MSG_RM_RESERVED_1111", "group__tisci__protocol.html#gab4133f34e8bef07211d22c5bf9e8ba80", null ],
    [ "TISCI_MSG_RM_RING_MON_CFG", "group__tisci__protocol.html#ga2d88c74d218a5672ccb6494a84f74a0d", null ],
    [ "TISCI_MSG_RM_RESERVED_1200", "group__tisci__protocol.html#ga7b01e96328447257f6887d3ba2088c8f", null ],
    [ "TISCI_MSG_RM_RESERVED_1201", "group__tisci__protocol.html#ga969e344fdf4859b5264a0b1e2f4acf7c", null ],
    [ "TISCI_MSG_RM_UDMAP_TX_CH_CFG", "group__tisci__protocol.html#ga5201d1265e4c7b25e8cf7a8f54dc3357", null ],
    [ "TISCI_MSG_RM_RESERVED_1206", "group__tisci__protocol.html#gad112cc9a50bdf05f194915216a913701", null ],
    [ "TISCI_MSG_RM_RESERVED_1210", "group__tisci__protocol.html#gaa394b21d9b1f7f0db060ede03f748dd2", null ],
    [ "TISCI_MSG_RM_RESERVED_1211", "group__tisci__protocol.html#ga42e5332bab34f3e0e9180a2ac49ef8ee", null ],
    [ "TISCI_MSG_RM_UDMAP_RX_CH_CFG", "group__tisci__protocol.html#ga1fc11a30b2db737766bd5f20cc68b568", null ],
    [ "TISCI_MSG_RM_RESERVED_1216", "group__tisci__protocol.html#ga1da2e16505ab57ba257694e12a7eea2d", null ],
    [ "TISCI_MSG_RM_RESERVED_1220", "group__tisci__protocol.html#gaca6e35109ece8be9ef19b324aedbfa00", null ],
    [ "TISCI_MSG_RM_RESERVED_1221", "group__tisci__protocol.html#ga66c5d0b7cccf2bd4e00c675b237832f9", null ],
    [ "TISCI_MSG_RM_UDMAP_FLOW_CFG", "group__tisci__protocol.html#gab185ac3f09c76172474197fadeea8656", null ],
    [ "TISCI_MSG_RM_UDMAP_FLOW_SIZE_THRESH_CFG", "group__tisci__protocol.html#ga21c0387cd3713438676b21ba2455c1bc", null ],
    [ "TISCI_MSG_RM_RESERVED_1232", "group__tisci__protocol.html#ga5c5f20f763b298f8e42e9bada78ed47e", null ],
    [ "TISCI_MSG_RM_RESERVED_1233", "group__tisci__protocol.html#gabff96caa857059924c2e9b88bda78a81", null ],
    [ "TISCI_MSG_RM_UDMAP_FLOW_DELEGATE", "group__tisci__protocol.html#ga072e79b15abdb79776469f2cb7e421a5", null ],
    [ "TISCI_MSG_RM_UDMAP_GCFG_CFG", "group__tisci__protocol.html#gaf581287b68e023b25f696429ffcba49f", null ],
    [ "TISCI_MSG_RM_RESERVED_1241", "group__tisci__protocol.html#ga4a2ef00449c0c3d471978c16d7c65024", null ],
    [ "TISCI_MSG_RM_PSIL_PAIR", "group__tisci__protocol.html#ga4a52dffe356097f666e5e1413717f22a", null ],
    [ "TISCI_MSG_RM_PSIL_UNPAIR", "group__tisci__protocol.html#gaf24cd1ea8e046855e1e52aabf52e3094", null ],
    [ "TISCI_MSG_RM_PSIL_READ", "group__tisci__protocol.html#ga12e9d3e960d12991e702dad907cf490e", null ],
    [ "TISCI_MSG_RM_PSIL_WRITE", "group__tisci__protocol.html#gaffbc4ab20a616d08b0234bd8592abd40", null ],
    [ "TISCI_MSG_RM_PROXY_CFG", "group__tisci__protocol.html#ga4fd145fe96160f50e8fc19c054913965", null ]
];