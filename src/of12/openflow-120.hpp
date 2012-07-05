/* Copyright(c) 2010-2011 The Board of Trustees of The Leland Stanford Junior University */

#ifndef HDR_OPENFLOW_120_HPP
#define HDR_OPENFLOW_120_HPP

#define OFP_120_NS openflow_120

#include <string.h>
#include <openflow-common.hpp>
#include <util/FieldManager.hpp>


#define PROTO_TAG_OPENFLOW_VER "OFP 1.2"

// Wireshark isn't a C++ application, so don't try
// to initialize C++ objects before main()

namespace openflow_120 {
    static const guint16 gVersion = 0x03;
    
    // Importing from epan/tfs.h wreaks havoc
    const true_false_string tfs_set_notset = {"Set", "Not set"};

    class DLLEXPORT DissectorContext {
    public:
        static DissectorContext* getInstance(int);
        void setHandles(dissector_handle_t, dissector_handle_t);
        static void prepDissect(tvbuff_t *, packet_info *, proto_tree *);
        void dissect(tvbuff_t *, packet_info *, proto_tree *);
        static guint getMessageLen(packet_info *, tvbuff_t *, int);
        
    private:
        DissectorContext(int);

        void setupCodes(void);
        void setupFlags(void);
        void setupFields(void);
        
        void dispatchMessage(tvbuff_t *, packet_info *, proto_tree *);
        void dissect_ofp_error();
        void dissect_ofp_echo();
        void dissectFeaturesRequest();
        void dissect_ofp_switch_features();
        void dissect_ofp_switch_config();
        void dissectStatsRequest();
        void dissectStatsReply();
        void dissect_ofp_portStatus();
        void dissect_ofp_flow_mod();
        void dissect_ofp_table_mod();
        void dissectGroupMod();
        void dissect_ofp_match(proto_tree *);
        void dissect_ofp_port(proto_tree *);
        void dissectOFPPF(proto_tree*);
        void dissect_ofp_instruction(proto_tree *);
        void dissect_ofp_action(proto_tree *);
        void dissectGroupBucket(proto_tree *);
        void dissect_ofp_oxm(proto_tree *, guint32 length);
        int dissect_ofp_oxm_field(proto_tree*);
        void dissect_ofp_packet_in();
        void dissect_ofp_packet_out();
        void dissect_ofp_role_request();
        
        dissector_handle_t mDataHandle;
        dissector_handle_t mOpenflowHandle;
        int mProtoOpenflow;
        FieldManager mFM;

        // Temporary context for dissection
        tvbuff_t *_tvb;
        packet_info *_pinfo;
        proto_tree *_tree;
        guint32 _offset;
        guint32 _rawLen;
        guint16 _oflen;
        proto_tree *_curOFPSubtree;
        static DissectorContext *mSingle;
        
        // Generated code
        GArray* ofp_type;
        GArray* ofp_port_no;
        GArray* ofp_queue_properties;
        GArray* ofp_match_type;
        GArray* ofp_oxm_class;
        GArray* oxm_ofb_match_fields;
        GArray* ofp_vlan_id;
        GArray* ofp_instruction_type;
        GArray* ofp_action_type;
        GArray* ofp_controller_max_len;
        GArray* ofp_table;
        GArray* ofp_flow_mod_command;
        GArray* ofp_group;
        GArray* ofp_group_mod_command;
        GArray* ofp_group_type;
        GArray* ofp_stats_types;
        GArray* ofp_controller_role;
        GArray* ofp_packet_in_reason;
        GArray* ofp_flow_removed_reason;
        GArray* ofp_port_reason;
        GArray* ofp_error_type;
        GArray* ofp_hello_failed_code;
        GArray* ofp_bad_request_code;
        GArray* ofp_bad_action_code;
        GArray* ofp_bad_instruction_code;
        GArray* ofp_bad_match_code;
        GArray* ofp_flow_mod_failed_code;
        GArray* ofp_group_mod_failed_code;
        GArray* ofp_port_mod_failed_code;
        GArray* ofp_table_mod_failed_code;
        GArray* ofp_queue_op_failed_code;
        GArray* ofp_switch_config_failed_code;
        GArray* ofp_role_request_failed_code;        
    };

    void init(int);
    extern DissectorContext * Context;
}

#endif // Header guard
