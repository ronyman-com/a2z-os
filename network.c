void send_packet(uint8_t* data, uint32_t size);
void receive_packet(uint8_t* buffer);
void ip_send(uint8_t* data, uint32_t size, uint32_t dest_ip);
void tcp_send(uint8_t* data, uint32_t size, uint32_t dest_ip, uint16_t dest_port);
